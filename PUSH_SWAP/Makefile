NAME	=	push_swap
SRCS	=	push_swap.c \
			
OBJS 	=	$(SRCS:.c=.o)

FLGS 	=	cc -Wall -Wextra -Werror
MYAR	=	MYLIB/mylib.a
MYH		=	MYLIB/mylib.h
RM		=	rm -f

GREEN	=	"\033[1;32m"
YELOW 	=	"\033[1;33m"
REDCL 	=	"\033[1;31m"
RESET 	=	"\033[0m"

all: $(MYAR) $(NAME)
	@echo $(GREEN)Done !!$(RESET)

$(MYAR):
	@make -C MYLIB --no-print-directory

$(NAME): $(OBJS) $(MYAR)
	@$(FLGS) $^ -o $(NAME)

$(OBJS): %.o: %.c $(MYHD)
	@$(FLGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C MYLIB
	@echo $(YELOW)Done !!$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C MYLIB
	@echo $(REDCL)Done !!$(RESET)

re: fclean all
