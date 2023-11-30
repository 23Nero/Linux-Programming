#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() 
{
    // Creat file to write
    FILE *file = fopen("test.txt", "w");

    fprintf(file, "Hello Linux programing\n");

    fclose(file);

    // Use struct stat get information
    struct stat file_stat;
    if (stat("test.txt", &file_stat) == 0) 
    {
        printf("Type number: %o\n", file_stat.st_mode & S_IFMT);
        printf("Name: %s\n", "test.txt");
        printf("Last time: %s", ctime(&file_stat.st_mtime));
        printf("Size: %lld bytes\n", (long long)file_stat.st_size);
    } 
    else 
    {
        // Nothing
    }


    return 0;
}
