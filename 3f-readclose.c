#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd[2];
    char buf1[25] = "just a test\n";
    char buf2[50];

    fd[0] = open("file1", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // Added flags to create or truncate the file
    fd[1] = open("file2", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd[0] == -1 || fd[1] == -1) {
        perror("Error opening file");
        return 1;
    }

    write(fd[0], buf1, strlen(buf1));

    printf("\nEnter the text now: ");
    fgets(buf1, sizeof(buf1), stdin); // Replaced gets() with fgets() for safer input

    write(fd[0], buf1, strlen(buf1));

    lseek(fd[0], 0, SEEK_SET); // Corrected the lseek() usage

    read(fd[0], buf2, sizeof(buf2));
    write(fd[1], buf2, strlen(buf2)); // Changed sizeof(buf2) to strlen(buf2)

    close(fd[0]);
    close(fd[1]);

    printf("\n");
    return 0;
}
