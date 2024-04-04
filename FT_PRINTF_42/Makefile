NAME		=	libftprintf.a
HEADER		=	ft_printf.h

SRCS		=	ft_printf.c   \
				ft_print_hex.c \
				ft_print_char.c \
				ft_print_flags.c \
				ft_print_string.c \
				ft_print_number.c  \
				ft_print_address.c  \
				ft_print_unsigned.c

FLGS		=	cc -Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS:.c=.o)

MYAR		=	MYLIB/libar.a
MYLB		=	MYLIB

ARRC		=	ar -rc
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(MYLB) $(NAME)
	@echo $(GREEN)Done !!$(RESET)

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@cp $(MYAR) $(NAME)
	@$(ARRC) $(NAME) $(OBJS)

bonus: $(MYLB) $(OBJS_BONUS)
	@cp $(MYAR) $(NAME)
	@$(ARRC) $(NAME) $(OBJS_BONUS)
	@echo $(GREEN)Done !!$(RESET)

%.o: %.c $(HEADER) $(MYAR)
	@$(FLGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C MYLIB --no-print-directory
	@echo $(YELOW)Done !!$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C MYLIB --no-print-directory
	@echo $(REDCL)Done !!$(RESET)

re: fclean all

.PHONY: $(MYLB)
