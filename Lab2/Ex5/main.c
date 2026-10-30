#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Hello Multi LKM");

//Khai báo hàm helper_greet() được định nghĩa trong file khác
extern void helper_greet(void);

//Hàm khởi tạo
static int __init hello_multi_init(void){
    //In log khi nạp module
    printk(KERN_INFO "hello_multi: module loaded\n");
    //Gọi hàm helper_greet() từ file helper.c
    helper_greet();
    return 0;
}

//Hàm thoát
static void __exit hello_multi_exit(void){
    //In log trước khi gỡ module
    printk(KERN_INFO "hello multi: module unloaded\n");
}

//Đăng ký entry và exit
module_init(hello_multi_init);
module_exit(hello_multi_exit);
