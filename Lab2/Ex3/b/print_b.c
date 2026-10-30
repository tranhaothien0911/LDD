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
static int __init print_b_init(void){
    int i;
    int result = 0;
    for(i = 1; i <= n; i++){
        result += i * i;
    }
    //Ghi log kết quả tính tổng bình phương từ 1 đến n
    printk(KERN_INFO "Result: %d\n", result);
    return 0;
}

//Hàm thoát
static void __exit print_b_exit(void){
    printk(KERN_INFO "Done with n=%d \n", n);
}

//Đăng ký entry và exit
module_init(print_b_init);
module_exit(print_b_exit);