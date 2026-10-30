//Cung cấp các macro module_init, module_exit, MODULE_LICENSE...
#include <linux/module.h>

//Định nghĩa các từ khóa __init và __exit
#include <linux/init.h>

//Cung cấp các hàm tiện ích cơ bản trong kernel
#include <linux/kernel.h>

MODULE_LICENSE("GPL"); //Khai báo giấy phép
MODULE_AUTHOR("TQS"); //Thông tin người viết module
MODULE_DESCRIPTION("Hello LKM"); //Giải thích ngắn gọn chức năng module

//Hàm khởi tạo, được gọi ngay khi module được nạp thành công
static int __init hello_init(void){
    printk(KERN_INFO "Hello, Kernel!\n"); //Ghi log trong kernel với thông tin thông thường
    return 0;
}

//Hàm thoát, được gọi trước khih module bị gỡ khởi kernel
static void __exit hello_exit(void){
    printk(KERN_INFO "Goodbye, Kernal!\n");  //Ghi log giá trị thông thường
}

//Đăng ký khai báo entry và exit với kernel
module_init(hello_init);
module_exit(hello_exit);
