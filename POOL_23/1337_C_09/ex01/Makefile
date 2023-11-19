MAIN	= libft.a
SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
INCS	= -I includes
LIBC	= ar rc
LIBR	= ranlib
CCFL	= cc -Wall -Wextra -Werror
OBJS	= $(SRCS:.c=.o)
RM		= rm -fr

.c.o:
	$(CCFL) -c $< -o $(<:.c=.o) $(INCS)

$(MAIN): $(OBJS)
	$(LIBC) $(MAIN) $(OBJS)
	$(LIBR) $(MAIN)

all: $(MAIN)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(MAIN)

re: fclean all
