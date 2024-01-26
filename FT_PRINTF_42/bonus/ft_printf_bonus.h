/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:31:09 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/01 17:59:49 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../MYLIB/mylib.h"
# include <unistd.h>
# include <stdarg.h>

# define SPECIFIERS	"cspdiuxX%"
# define NUMBERS	"0123456789"
# define FLAGS		"-0.# +"

typedef struct s_flags
{
	int	minus;
	int	minus_len;
	int	zero;
	int	zero_len;
	int	dot;
	int	dot_len;
	int	hash;
	int	space;
	int	plus;
}				t_flags;

int	print_char(char c);
int	print_num(int num);
int	print_percent(void);
int	print_string(char *str);
int	print_address(void *ptr);
int	print_unum(unsigned int num);
int	print_hex(unsigned int num, char set);
int	ft_printf(const char *format, ...);
int	print_char_handler(char c, t_flags flags);
int	print_num_handler(int num, t_flags flags);
int	print_string_handler(char *str, t_flags flags);
int	print_address_handler(void *ptr, t_flags flags);
int	print_unum_handler(unsigned int num, t_flags flags);
int	print_hex_handler(unsigned int num, char set, t_flags flags);

#endif
