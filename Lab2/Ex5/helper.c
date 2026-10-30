#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Hello Multi LKM");

//Hàm helper để ghi log message, được gọi từ main.c
void helper_greet(void){
    printk(KERN_INFO "Hello from helper.c!\n");
}
