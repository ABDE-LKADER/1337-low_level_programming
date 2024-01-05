NAME				=	server
SRCS				=	server.c
OBJS				=	$(SRCS:.c=.o)

CLIENT_NAME 		=	client
CLIENT_SRCS			=	client.c
CLIENT_OBJS			=	$(CLIENT_SRCS:.c=.o)

NAME_BONUS			=	server_bonus
SRCS_BONUS			=	server_bonus.c
OBJS_BONUS			=	$(SRCS_BONUS:.c=.o)

CLIENT_NAME_BONUS 	=	client_bonus
CLIENT_SRCS_BONUS 	=	client_bonus.c
CLIENT_OBJS_BONUS 	=	$(CLIENT_SRCS_BONUS:.c=.o)

FLGS				=	cc -Wall -Wextra -Werror
MYAR				=	MYLIB/mylib.a
MYHD				=	MYLIB/mylib.h
RM					=	rm -f

all: $(MYAR) $(NAME) $(CLIENT_NAME)

bonus: $(MYAR) $(NAME_BONUS) $(CLIENT_NAME_BONUS)

$(MYAR):
	@make -C MYLIB --no-print-directory

$(NAME): $(OBJS) $(MYAR)
	$(FLGS) $^ -o $(NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) $(MYAR)
	$(FLGS) $^ -o $(CLIENT_NAME) 

$(OBJS): %.o: %.c $(MYHD)
	$(FLGS) -c $< -o $@

$(CLIENT_OBJS): %.o: %.c $(MYHD)
	$(FLGS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(MYAR)
	$(FLGS) $^ -o $(NAME_BONUS)

$(CLIENT_NAME_BONUS): $(CLIENT_OBJS_BONUS) $(MYAR)
	$(FLGS) $^ -o $(CLIENT_NAME_BONUS) 

$(OBJS_BONUS): %.o: %.c $(MYHD)
	$(FLGS) -c $< -o $@

$(CLIENT_OBJS_BONUS): %.o: %.c $(MYHD)
	$(FLGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CLIENT_OBJS) $(OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@make clean -C MYLIB --no-print-directory

fclean: clean
	$(RM) $(NAME) $(CLIENT_NAME) $(NAME_BONUS) $(CLIENT_NAME_BONUS)
	@make fclean -C MYLIB --no-print-directory

re: fclean all
