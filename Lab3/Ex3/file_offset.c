#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    //Yêu cầu 2: mở cùng 1 tệp 2 lần
    int fd1 = open("sample.txt", O_RDONLY);
    int fd2 = open("sample.txt", O_RDONLY);
    int fd3 = dup(fd1);

    if(fd1 == -1 || fd2 == -1){
        perror("open");
        close(fd1);
        close(fd2);
        return 1;
    }

    printf("Yeu cau 2: mo cung 1 tep 2 lan\n");
    char buf[20] = {0};
    //Đọc 2 ký tự của fd1
    if(read(fd1, buf, 2) == -1){
        perror("read fd1");
        close(fd1);
        close(fd2);
        return 1;
    }
    //In ra dữ liệu đọc được và offset file của fd1
    printf("File descriptor 1: %s\n", buf);
    printf("Offset fd1: %ld\n", lseek(fd1, 0, SEEK_CUR));

    //Đọc 2 ký tự của fd2
    if(read(fd2, buf, 2) == -1){
        perror("read fd2");
        close(fd1);
        close(fd2);
        return 1;
    }
    //In ra dữ liệu đọc đc và offset file của fd2
    printf("File descriptor 2: %s\n", buf);
    printf("Offset fd2: %ld\n", lseek(fd2, 0, SEEK_CUR));
    printf("-------------------------------\n");

    //Yêu cầu 3: tạo thêm 1 descriptor bằng dup
    printf("Yeu cau 3: tao them 1 fd bang dup\n");
    //int fd3 = dup(fd1);

    //Đọc 2 ký tự của fd3
    if(read(fd3, buf, 2) == -1){
        perror("read f3");
        close(fd1);
        close(fd2);
        close(fd3);
    }

    //In ra dữ liệu đọc đc và offset file của fd3
    printf("File descriptor 3: %s\n", buf);
    printf("Offset fd3: %ld\n", lseek(fd3, 0, SEEK_CUR));

     if(read(fd1, buf, 2) == -1){
        perror("read fd1");
        close(fd1);
        close(fd2);
        return 1;
    }
    //In ra dữ liệu đọc được và offset file của fd1
    printf("File descriptor 1: %s\n", buf);
    printf("Offset fd1: %ld\n", lseek(fd1, 0, SEEK_CUR));

    //Đọc 2 ký tự của fd2
    if(read(fd2, buf, 2) == -1){
        perror("read fd2");
        close(fd1);
        close(fd2);
        return 1;
    }
    //In ra dữ liệu đọc đc và offset file của fd2
    printf("File descriptor 2: %s\n", buf);
    printf("Offset fd2: %ld\n", lseek(fd2, 0, SEEK_CUR));
    printf("-------------------------------\n");

    //Yêu cầu 4: Đưa file offset của fd1 về 0

    printf("Yeu cau 4\n");
    if(lseek(fd1, 0, SEEK_SET) < 0){
        perror("lseek");
        close(fd1);
        close(fd2);
        close(fd3);
        return 1;
    }

    //In ra offset của 3 fd
    printf("Offset fd2: %ld\n", lseek(fd2, 0, SEEK_CUR));
    printf("Offset fd3: %ld\n", lseek(fd3, 0, SEEK_CUR));
    printf("-------------------------------\n");

    close(fd1);
    close(fd2);
    close(fd3);
}