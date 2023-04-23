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



static struct task_struct *my_thread;
static char *argv[] = { "/root/pet_game_screensaver", NULL };
static struct subprocess_info *sub_info;
static pid_t screensaver_pid;

static ssize_t write_pid(struct file *filp,	const char *buf, size_t count, loff_t *f_pos);
static int ss_open(struct inode *inode, struct file *filp){return 0;}
static int ss_release(struct inode *inode, struct file *filp){return 0;}


struct file_operations kscreensaver_fops = {
	write: write_pid,
	open: ss_open,
	release: ss_release,
};


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

    // call_usermodehelper(argv[0], argv, NULL, UMH_WAIT_EXEC);
    sub_info = call_usermodehelper_setup(argv[0], argv, NULL, GFP_KERNEL, NULL, NULL, NULL);
    if (sub_info == NULL) {
        printk(KERN_ERR "Failed to set up usermode helper process\n");
        return -ENOMEM;
    }    
    result = call_usermodehelper_exec(sub_info, UMH_NO_WAIT);
    if (result) {
        printk(KERN_ERR "Failed to execute usermode helper process\n");
        return result;
    }
    printk(KERN_ALERT "pid: %d\n",(sub_info->pid)); // Does not work, sub_info->pid is incorrect

    return 0;
}
static void screenlauncher_exit(void){
    printk(KERN_INFO "Exiting screensaverlauncher\n");
    if (sub_info != NULL) {
        printk(KERN_INFO "Killing screensaver with pid %d\n", screensaver_pid);
        send_sig(SIGKILL, pid_task(find_vpid(screensaver_pid),PIDTYPE_PID), 1);
    }
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
    printk(KERN_INFO "Screensaver with pid %d\n", screensaver_pid);

    *f_pos += count;

    return count;
}