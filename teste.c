#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    char *line_start = buffer;
    char *line_end = buffer;
    int line_length;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        line_end = line_start;
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                line_length = line_end - line_start;
                char line[line_length + 1];
                strncpy(line, line_start, line_length);
                line[line_length] = '\0';
                printf("%s\n", line);
                line_start = line_end + 1;
            }
            line_end++;
        }
    }

    // Print the last line if it didn't end with a newline
    if (line_start != line_end) {
        line_length = line_end - line_start;
        char line[line_length + 1];
        strncpy(line, line_start, line_length);
        line[line_length] = '\0';
        printf("%s\n", line);
    }

    close(fd);
    return 0;
}
