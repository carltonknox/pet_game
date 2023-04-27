#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/sched/signal.h> // for send_sig()
#include <linux/signal.h>
#include <asm/uaccess.h> /* copy_from/to_user */
#include <linux/fs.h> /* everything... */
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/uaccess.h>
#include <linux/input.h>
#include <linux/time.h>
#include <linux/input.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/time.h>


#define TOUCH_DEV "/dev/input/event0"

struct input_event touch_event;
int last_touch_timestamp;
int got_pid;


static struct task_struct *mythread;
static char *argv[] = { "/root/pet_game_screensaver", NULL };
static pid_t screensaver_pid;

static ssize_t write_pid(struct file *filp,	const char *buf, size_t count, loff_t *f_pos);
static int ss_open(struct inode *inode, struct file *filp){return 0;}
static int ss_release(struct inode *inode, struct file *filp){return 0;}


struct file_operations kscreensaver_fops = {
	write: write_pid,
	open: ss_open,
	release: ss_release,
};




static int screensavermanager(void* arg)
{
    
    //run in background, check /dev/input/event0 for user input, then run screensaver if needed
    int running;
    struct file *file;
    struct input_event event;
    struct timeval event_timeval;
    struct timeval current_timeval;
    do_gettimeofday(&event_timeval);
    do_gettimeofday(&current_timeval);

    file = filp_open("/dev/input/event0", O_RDONLY | O_NONBLOCK, 0);
    if (IS_ERR(file)) {
        printk(KERN_ALERT "Failed to open /dev/input/event0\n");
        return -1;
    }
    

    running = got_pid=0;
    // call_usermodehelper(argv[0], argv, NULL, UMH_NO_WAIT);
    // running=1;    
    while(!kthread_should_stop())
    {
        if(vfs_read(file, (void*)(&event), sizeof(event), &file->f_pos) == sizeof(event)){
            if (event.type == EV_SYN) {
                // This is a synchronization event, which indicates the end of an event sequence
                printk(KERN_INFO "Last input received at time: %ld.%06ld\n", event.__sec, event.__usec);
                event_timeval.tv_sec=event.__sec;
                event_timeval.tv_usec=event.__usec;
            }
        }
        else
            msleep(100);

        do_gettimeofday(&current_timeval);
        printk(KERN_INFO "time since last press: %ld\n", current_timeval.tv_sec-event_timeval.tv_sec);
        if(current_timeval.tv_sec-event_timeval.tv_sec >= 15){
            //start screensaver
            if(!running){
                got_pid=0;
                call_usermodehelper(argv[0], argv, NULL, UMH_NO_WAIT);
                running=1;
            }    
        }
        else if(running&&got_pid){
            printk(KERN_INFO "Killing screensaver with pid %d\n", screensaver_pid);
            send_sig(SIGKILL, pid_task(find_vpid(screensaver_pid),PIDTYPE_PID), 1);
            running=0;
            got_pid=0;
        }


    }
    filp_close(file, NULL);
    if (running&&got_pid) {
        printk(KERN_INFO "Killing screensaver with pid %d\n", screensaver_pid);
        send_sig(SIGKILL, pid_task(find_vpid(screensaver_pid),PIDTYPE_PID), 1);
    }
    return 0;

}


static int screenlauncher_init(void){
    int result;    

    printk(KERN_INFO "Starting screensaver\n");

    result = register_chrdev(61, "kscreensaverlauncher", &kscreensaver_fops);
    if (result < 0)
	{
		printk(KERN_ALERT
			"mytraffic: cannot obtain major number %d\n", 61);
        unregister_chrdev(61, "kscreensaverlauncher");
		return result;
	}

    //setup thread to run user program when idle:
    mythread = kthread_create(screensavermanager, NULL, "mythread");
    if (IS_ERR(mythread)) {
        printk(KERN_ERR "Failed to create kernel thread\n");
        return PTR_ERR(mythread);
    }
    wake_up_process(mythread); 

    


    return 0;
}
static void screenlauncher_exit(void){
    printk(KERN_INFO "Exiting screensaverlauncher\n");
    if(!IS_ERR(mythread))
        kthread_stop(mythread);
    
    unregister_chrdev(61, "kscreensaverlauncher");
}
module_init(screenlauncher_init);
module_exit(screenlauncher_exit);
MODULE_LICENSE("GPL");

static ssize_t write_pid(struct file *filp,	const char *buf, size_t count, loff_t *f_pos){
    pid_t input;
    if(*f_pos >=sizeof(pid_t))
        return 0;
    if (copy_from_user(&input, buf, sizeof(pid_t)))
	{
		return -EFAULT;
	}

    screensaver_pid=input;
    got_pid=1;
    printk(KERN_INFO "Screensaver with pid %d\n", screensaver_pid);

    *f_pos += count;

    return count;
}

