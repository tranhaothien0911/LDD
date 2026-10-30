#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Hello param LKM");

//Khai báo các tham số truyền vào module
static char *whom = "world";
static int howmany = 1;

//Lập trình module nhận một giá trị đơn lẻ
module_param(whom, charp, 0644); //Biến whom dạng string với toàn quyền truy cập
module_param(howmany, int, 0644);//Biến howmany dạng int với toàn quyền truy cập

//Hàm khởi tạo
static int __init hello_param_init(void){
    int i;
    //Ghi log dữ liệu howmany lần với giá trị của whom và i
    for(i = 1; i <= howmany; i++){
        printk(KERN_INFO "Hello, %s! %d \n", whom, i);
    }
    return 0;
}

//Hàm thoát
static void __exit hello_param_exit(void){
    //Trước khi gỡ module, ghi log message
    printk(KERN_INFO "Bye, %s!\n", whom);
}

//Đăng ký entry và exit
module_init(hello_param_init);
module_exit(hello_param_exit);