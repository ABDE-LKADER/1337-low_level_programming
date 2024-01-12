NAME =	mylib.a
LIBF =	mylib.h
SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_printf.c ft_printf_plus.c
ARRC =	ar -rc
FLGS =	cc -Wall -Wextra -Werror -c
OBJS =	$(SRCS:.c=.o)
RM   =	rm -fr

GREEN =	"\033[1;32m"
YELOW =	"\033[1;33m"
REDCL = "\033[1;31m"
RESET =	"\033[0m"

all: $(NAME)
	@echo $(GREEN)MYLIB Created !!$(RESET)

$(NAME): $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)

%.o: %.c $(LIBF)
	@$(FLGS) $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo $(YELOW)MYLIB Cleaned !!$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(REDCL)MYLIB Cleared !!$(RESET)

re: fclean all
