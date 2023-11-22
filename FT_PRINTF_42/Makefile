NAME =	libftprintf.a
LIBH =	printf.h
SRCS =	ft_printf.c ft_printf_utils.c
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

.PHONY: all clean fclean re
