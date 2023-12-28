NAME =	libftprintf.a
LIBH =	ft_printf.h
SRCS =	ft_printf.c ft_printf_utils.c ft_printf_plus.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_strlen.c ./libft/ft_strchr.c
FLGS =	cc -c -Wall -Wextra -Werror
ARRC =	ar -rc
OBJS =	$(SRCS:.c=.o)
RM	 =	rm -fr

%.o: %.c $(LIBH)
	$(FLGS) $< -o $@

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
