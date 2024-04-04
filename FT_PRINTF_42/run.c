#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

# define SET  "%-10.5d", -1862

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
