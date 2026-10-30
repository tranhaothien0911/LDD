#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Hello Array LKM");

//Khai báo tham số truyền vào module
static int nums[10];
static int num_count = 0;

//Lập trình module nhận giá trị truyền vào
module_param_array(nums, int, &num_count, 0644);

//Hàm khởi tạo
static int __init hello_array_init(void){
    int i;
    int sum = 0;
    //Ghi log từng giá trị trong mảng nums và tính tổng các phần tử
    printk(KERN_INFO "Array elements: ");
    for(i = 0; i < num_count; i++){
        sum += nums[i];
        printk(KERN_INFO "Nums[i] = %d \n", nums[i]);
    }
    //Ghi log tổng các phần tử trong mảng
    printk(KERN_INFO "Sum of array elements: %d\n", sum);
    return 0;
}

//Hàm thoát
static void __exit hello_array_exit(void){
    //Ghi log trước khi module bị gỡ bỏ
    printk(KERN_INFO "hello_multi: module unloaded\n");
}

//Đăng ký entry và exit
module_init(hello_array_init);
module_exit(hello_array_exit);