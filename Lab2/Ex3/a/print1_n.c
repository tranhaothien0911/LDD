#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Print 1 to n LKM");

//Khai báo tham số truyền vào module
static int n = 1;

//Lập trình module nhận giá trị truyền vào
module_param(n, int, 0644);

//Hàm khởi tạo
static int __init print1_n_init(void){
    int i;
    //Ghi log giá trị từ 1 đến n
    for(i = 1; i <= n; i++){
        printk(KERN_INFO "%d\n", i);
    }
    return 0;
}

//Hàm thoát
static void __exit print1_n_exit(void){
    //Trước khi gỡ module, ghi log giá trị cuối cùng
    printk(KERN_INFO "Done with n=%d \n", n);
}

//Đăng ký entry và exit
module_init(print1_n_init);
module_exit(print1_n_exit);