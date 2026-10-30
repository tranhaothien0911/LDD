#ifndef _COMMON_H_
#define _COMMON_H_

//Struct lưu kết quả tính toán
struct stats_result{
    int sum;
    int avg;
    int max;
    int min;
};

int compute_stats(const int *array, int size, struct stats_result *result);

#endif