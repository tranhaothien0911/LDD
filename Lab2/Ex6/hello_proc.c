#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h> //Cung cấp định nghĩa current và struct task_struct

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Hello Process LKM");

//Hàm khởi tạo
static int __init hello_proc_init(void){
    //Ghi log thông tin về tiến trình hiện tại khi nạp module
    //current là con trỏ trỏ đến struct task_struct của tiến trình hiện tại
    //current->comm: chứa tên của tiến trình đang chạy
    //current->pid: chứa ID của tiến trình đang chạy
    printk(KERN_INFO "hello_proc: loaded by process %s (pid = %d)\n", current->comm, current->pid);
    return 0;
}

//Hàm thoát
static void __exit hello_proc_exit(void){
    printk(KERN_INFO "hello_proc: unloaded \n");
}

//Đăng ký entry và exit
module_init(hello_proc_init);
module_exit(hello_proc_exit);
