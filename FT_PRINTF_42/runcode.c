#include <stdio.h>
#include "libftprintf.h"

int		main(void)
{
	char *s = NULL;
	ft_printf("My: %c \n", 'c');
	printf("Def: %c \n", 'c');

	ft_printf("My: %s \n", s);
	printf("Def: %s \n", s);

	ft_printf("My: %s\n", "hhhhhhhhhhhh");
	printf("Def: %s\n", "hhhhhhhhhhhh");

	ft_printf("My: %p \n", "hhhhhhhhhhhh");
	printf("Def: %p \n", "hhhhhhhhhhhh");
}
