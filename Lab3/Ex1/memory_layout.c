#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Khởi tạo biến toàn cục khác 0
int global_value = 100;

//Khởi tạo biến toàn cục không tường minh
int global_variable;


int main(){
    static int static_local_value = 10; //Khởi tạo biến static trong hàm main()
    int local_value = 15; //Khởi tạo biến cục bộ

    //Cấp phát động
    int *heap_value = malloc(sizeof(int));
    if(heap_value == NULL){
        perror("malloc");
        return 1;
    }
    *heap_value = 20;

    //In ra PID của tiến trình đang chạy
    printf("Process ID: %d\n", getpid());

    //In ra địa chỉ ảo của từng biến
    printf("Global value: %p\n", (void*) &global_value);
    printf("Global varibale: %p\n", (void*)&global_variable);
    printf("Static local value: %p\n", (void*)&static_local_value);
    printf("Local value: %p\n", (void*)&local_value);
    printf("Heap value: %p\n",(void *) heap_value);

    //Tạm dừng chương trình cho đến khi người dùng nhấn enter
    getchar();

    //Giải phóng bộ nhớ động
    free(heap_value);
    return 0;
}