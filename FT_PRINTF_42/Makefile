# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 06:38:56 by abadouab          #+#    #+#              #
#    Updated: 2024/04/05 07:48:08 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	mandatory/ft_printf.c \
				mandatory/ft_printf_plus.c

SRCS_BONUS	=	bonus/ft_print_hex.c \
				bonus/ft_print_char.c \
				bonus/ft_print_flags.c \
				bonus/ft_print_string.c \
				bonus/ft_print_number.c  \
				bonus/ft_printf_bonus.c   \
				bonus/ft_print_address.c   \
				bonus/ft_print_unsigned.c

FLGS		=	cc -Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS 	=	$(SRCS_BONUS:.c=.o)

HEADER		=	mandatory/ft_printf.h
HD_BONUS	=	bonus/ft_printf_bonus.h

MYAR		=	MYLIB/libar.a
MYLB		=	MYLIB

ARRC		=	ar -rc
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: start $(MYLB) $(NAME) finish 

start:
	@printf "\n"
	@echo $(GREEN)"Starting build..."
	@sleep 1
	@printf "Loading [ "

finish:
	@echo $(GREEN) ] 100%$(RESET)
	@echo $(GREEN)Project built.$(RESET)
	@printf "\n"

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@cp $(MYAR) $(NAME)
	@$(ARRC) $(NAME) $(OBJS)

$(OBJS): %.o: %.c $(HEADER) $(MYAR)
	@$(FLGS) -c $< -I $(MYLB) -o $@
	@printf $(GREEN)"."$(RESET)

bonus: start $(MYLB) $(OBJS_BONUS) finish
	@cp $(MYAR) $(NAME)
	@$(ARRC) $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS): %.o: %.c $(HD_BONUS) $(MYAR)
	@$(FLGS) -c $< -I $(MYLB) -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(MYLB) --no-print-directory
	@echo $(YELOW)Cleaning up 🧹💫$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(MYLB) --no-print-directory
	@echo $(REDCL)Purging all files 🗑️$(RESET)

re: fclean all

.PHONY: $(MYLB)
