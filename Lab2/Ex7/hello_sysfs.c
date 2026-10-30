#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Hello sysfs LKM");

//Khai báo tham số truyền vào module
static int val = 0;

//Lập trình module nhận giá trị truyền vào
module_param(val, int, 0644);

//Hàm khởi tạo
static int __init hello_sysfs_init(void){
    //Ghi log giá trị của tham số val khi nạp module
    printk(KERN_INFO "hello_sysfs: loaded with val = %d \n", val);
    return 0;
}

//Hàm thoát
static void __exit hello_sysfs_exit(void){
    //Ghi log trước khi module bị gỡ bỏ
    printk(KERN_INFO "hello_sysfs: unloaded\n");
}

//Đăng ký entry và exit
module_init(hello_sysfs_init);
module_exit(hello_sysfs_exit);
