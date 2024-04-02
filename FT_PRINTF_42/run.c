#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int len;
    printf("ORIGINAL:\n");
    len = printf("%-.13s", NULL);
    printf("-------> %d", len);
    printf("\n");
    printf("OWN:\n");
    len = ft_printf("%-.13s", NULL);
    printf("-------> %d", len);
    printf("\n");
}
