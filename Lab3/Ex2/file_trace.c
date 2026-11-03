#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    //Mở file với các cờ đọc và ghi, tạo file nếu chưa tồn tại và xóa nội dung cũ nếu file đã tồn tại
    int fd = open("data.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    //Kiểm tra giá trị hợp lệ của fd
    if(fd == -1){
        perror("File descriptor");
        return 1;
    }

    char message[13] = "Linux Driver";
    char buffer[13] = {0};

    //Ghi nội dung message vào file data.txt và kiểm tra giá trị trả về
    if(write(fd, message, sizeof(message) - 1) != sizeof(message) - 1){
        perror("write");
        close(fd);
        return 1;
    }

    //Dịch con trỏ file về vị trí đầu file và kiểm tra giá trị trả về
    if(lseek(fd, 0, SEEK_SET) == -1){
        perror("lseek");
        close(fd);
        return 1;
    }

    //Đọc giá trị từ file data.txt vào mảng buffer và kiểm tra giá trị trả về
    int cnt = read(fd, buffer,sizeof(buffer) - 1);
    if(cnt == -1){
        perror("read");
        close(fd);
        return 1;
    }

    //In ra dữ liệu đọc được và số byte đọc thực tế
    printf("Buffer read: %s\n", buffer);
    printf("Byte: %d\n", cnt);

    //Đóng files
    close(fd);
}