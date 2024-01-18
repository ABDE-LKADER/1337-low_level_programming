NAME		=	push_swap
SRCS		=	mandatory/parse_in.c \
				mandatory/push_swap.c \
				mandatory/actions_sp.c \
				mandatory/actions_ro.c  \
				mandatory/check_errors.c \
				mandatory/actions_plus.c  \

NAME_BONUS	=	checker
SRCS_BONUS	=	bonus/checker_bonus.c  \
				bonus/parse_in_bonus.c  \
				bonus/actions_sp_bonus.c \
				bonus/actions_ro_bonus.c  \
				bonus/check_errors_bonus.c \
				need_to_remove.c

OBJS 		=	$(SRCS:.c=.o)
OBJS_BONUS 	=	$(SRCS_BONUS:.c=.o)

FLGS 	=	cc -Wall -Wextra -Werror
MYAR	=	MYLIB/mylib.a
MYHD	=	MYLIB/mylib.h
RM		=	rm -f

GREEN	=	"\033[1;32m"
YELOW 	=	"\033[1;33m"
REDCL 	=	"\033[1;31m"
RESET 	=	"\033[0m"

all: $(MYAR) $(NAME)
	@echo $(GREEN)Done !!$(RESET)

bonus: $(MYAR) $(NAME_BONUS)
	@echo $(GREEN)Done !!$(RESET)

$(MYAR):
	@make -C MYLIB --no-print-directory

$(NAME): $(OBJS) $(MYAR)
	@$(FLGS) $^ -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(MYAR)
	@$(FLGS) $^ -o $(NAME_BONUS)

$(OBJS): %.o: %.c $(MYHD)
	@$(FLGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(MYHD)
	@$(FLGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C MYLIB
	@echo $(YELOW)Done !!$(RESET)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C MYLIB
	@echo $(REDCL)Done !!$(RESET)

re: fclean all
