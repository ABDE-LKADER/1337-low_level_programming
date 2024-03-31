#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
    int fd = open("multiple_nl.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
}
