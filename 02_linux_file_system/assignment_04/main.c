#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() 
{
    // Mở file hoặc tạo file nếu chưa tồn tại
    // O_WRONLY: Mở file để ghi
    // O_CREAT: Tạo file nếu chưa tồn tại
    // O_APPEND: Ghi dữ liệu vào cuối file
    int fileDescriptor = open("example.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fileDescriptor == -1) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Thực hiện seek về đầu file
    if (lseek(fileDescriptor, 0, SEEK_SET) == -1) 
    {
        perror("Error seeking to the beginning of the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }

    // Ghi dữ liệu vào file
    const char *data = "Hello, world!";
    if (write(fileDescriptor, data, strlen(data)) == -1) 
    {
        perror("Error writing to the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }

    // Đóng file
    if (close(fileDescriptor) == -1) 
    {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("Data was written to the beginning of the file.\n");

    return 0;
}
