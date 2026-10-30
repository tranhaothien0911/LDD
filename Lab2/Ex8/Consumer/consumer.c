#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "../common.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Consumer LKM");

//Hàm khởi tạo
static int __init consumer_init(void) {
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);
    struct stats_result result;
    int ret;

    printk(KERN_INFO "Consumer module loaded.\n");

    // Gọi hàm từ provider
    ret = compute_stats(data, size, &result);
    
    if (ret == 0) {
        printk(KERN_INFO "Sum: %d\n", result.sum);
        printk(KERN_INFO "Avg: %d\n", result.avg);
        printk(KERN_INFO "Max: %d\n", result.max);
        printk(KERN_INFO "Min: %d\n", result.min);
    } else {
        printk(KERN_ERR "Failed to compute stats with error code: %d\n", ret);
    }

    return 0;
}

//Hàm thoát
static void __exit consumer_exit(void) {
    printk(KERN_INFO "Consumer module unloaded.\n");
}

//Đăng ký entry và exit
module_init(consumer_init);
module_exit(consumer_exit);