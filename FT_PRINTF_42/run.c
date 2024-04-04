#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

# define HHH "%20.5d", -1024
# define SET "%-3i", 0

int main()
{
    int len;
    printf("ORIGINAL:\n");
    len = printf(SET);
    printf("-------> %d", len);
    printf("\n");
    printf("OWN:\n");
    len = ft_printf(SET);
    printf("-------> %d", len);
    printf("\n");
}
