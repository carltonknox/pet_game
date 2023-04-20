#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/sched/signal.h> // for send_sig()
#include <linux/signal.h>


static struct task_struct *my_thread;
static char *argv[] = { "/root/pet_game_screensaver", NULL };
static struct subprocess_info *sub_info;


static int screenlauncher_init(void){
    printk(KERN_INFO "Starting screensaver\n");
    // call_usermodehelper(argv[0], argv, NULL, UMH_WAIT_EXEC);
    sub_info = call_usermodehelper_setup(argv[0], argv, NULL, GFP_KERNEL, NULL, NULL, NULL);
    if (sub_info == NULL) {
        printk(KERN_ERR "Failed to set up usermode helper process\n");
        return -ENOMEM;
    }    
    int ret = call_usermodehelper_exec(sub_info, UMH_NO_WAIT);
    if (ret) {
        printk(KERN_ERR "Failed to execute usermode helper process\n");
        return ret;
    }
    printk(KERN_ALERT "pid: %d\n",(sub_info->pid)); // Does not work, sub_info->pid is incorrect

    return 0;
}
static void screenlauncher_exit(void){
    printk(KERN_INFO "Exiting screensaverlauncher\n");
    if (sub_info != NULL) {
        printk(KERN_INFO "Killing screensaver with pid %d\n", sub_info->pid);
        send_sig(SIGKILL, pid_task(find_vpid(sub_info->pid),PIDTYPE_PID), 1);
    }
}
module_init(screenlauncher_init);
module_exit(screenlauncher_exit);
MODULE_LICENSE("GPL");