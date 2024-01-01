NAME =	libftprintf.a
LIBH =	ft_printf.h
SRCS =	ft_printf.c ft_printf_plus.c ./SRCS/ft_putchar_fd.c ./SRCS/ft_putstr_fd.c ./SRCS/ft_strlen.c ./SRCS/ft_strchr.c
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
