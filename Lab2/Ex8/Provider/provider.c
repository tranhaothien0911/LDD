#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "../common.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TQS");
MODULE_DESCRIPTION("Provider LKM");

//Hàm thực hiện theo yêu cầu đề bài
int compute_stats(const int *array, int size, struct stats_result *result){
    int i;

    if(size <= 0 || array == NULL || result == NULL){
        return -1;
    }

    result->sum = 0;
    result->max = array[0];
    result->min = array[0];

    for(i = 0; i < size; i++){
        result->sum += array[i];
        if(array[i] > result->max){
            result->max = array[i];
        }
        if(array[i] < result->min){
            result->min = array[i];
        }
    }
    result->avg = result->sum / size;
    return 0;
}

//Đăng ký hàm compute_stats để các module khác có thể sử dụng
EXPORT_SYMBOL(compute_stats);

//Hàm khởi tạo
static int __init provider_init(void){
    printk(KERN_INFO "Provider module loaded\n");
    return 0;
}

//Hàm thoát
static void __exit provider_exit(void){
    printk(KERN_INFO "Provider module unloaded\n");
}

//Đăng ký entry và exit
module_init(provider_init);
module_exit(provider_exit);