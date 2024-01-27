NAME		=	libftprintf.a
HEADER		=	ft_printf.h

SRCS		=	mandatory/ft_printf.c \
				mandatory/ft_printf_plus.c

SRCS_BONUS	=	bonus/ft_print_hex.c   \
				bonus/ft_printf_bonus.c \
				bonus/ft_print_string.c  \
				bonus/ft_print_number.c   \
				bonus/ft_print_address.c   \
				bonus/ft_print_unsigned.c   \

FLGS		=	cc -Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

MYAR		=	MYLIB/libar.a
MYHD		=	MYLIB/mylib.h

ARRC		=	ar -rc
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(NAME)
	@echo $(GREEN)Done !!$(RESET)

$(NAME): $(OBJS)
	@make -C MYLIB --no-print-directory
	@cp $(MYAR) $(NAME)
	@$(ARRC) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	@make -C MYLIB --no-print-directory
	@cp $(MYAR) $(NAME)
	@$(ARRC) $(NAME) $(OBJS_BONUS)
	@echo $(GREEN)Done !!$(RESET)

%.o: %.c $(HEADER) $(MYHD)
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
