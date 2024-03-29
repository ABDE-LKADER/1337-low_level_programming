#include "get_next_line_bonus.c"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("~/francinette/tests/get_next_line/fsoares/multiple_nl.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
}
