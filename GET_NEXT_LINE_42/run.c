#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char	*to;
    char    *ok;
    int fd = open("test.txt", O_RDONLY);

    ok = get_next_line(fd);
    while (ok)
    {
        printf("%s", ok);
        free(ok);
        ok = get_next_line(fd);
    }
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // get_next_line(fd);
    // ok = rest;
    // printf("REAST ---------------> %s", rest);
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
}
