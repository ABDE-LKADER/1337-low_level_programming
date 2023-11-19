#!/bin/bash
cc -Wall -Wextra -Werror -c *.c
ar -rc libft.a *.o
rm *.o
