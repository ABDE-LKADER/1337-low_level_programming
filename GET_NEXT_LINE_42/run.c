#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	char	*to;
    static char    *ok;
    int fd = open("test.txt", O_RDONLY);

    // printf("%s", ok = strdup_next("HELLO T\n OK HELLO\n TESTER \nOK TESTER\n\n\n"));
    // printf("-------------------");
    // printf("%s", ok = strdup_next(ok));
    // printf("-------------------");
    // printf("%s", ok = strdup_next(ok));
    // printf("-------------------");
    // printf("%s", ok = strdup_next(ok));
    // printf("-------------------");
    // printf("%s", ok = strdup_next(ok));
    // printf("-------------------");
    // printf("%s", ok = strdup_next(ok));
    // printf("-------------------");
    // printf("%s", ok = strdup_next(ok));
    // printf("-------------------");
    // printf("%s", ft_strjoin("BONNNNNN ", " BAD THINGS OK"));
    // ok = get_next_line(fd);
    // while (ok)
    // {
    //     printf("%s", ok);
    //     free(ok);
    //     ok = get_next_line(fd);
    // }
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    get_next_line(fd);
    // ok = rest;
    // printf("REAST ---------------> %s", rest);
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
}
