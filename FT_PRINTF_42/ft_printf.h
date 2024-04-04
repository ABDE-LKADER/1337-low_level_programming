/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:31:09 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/04 06:35:36 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "MYLIB/mylib.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define SPECIFIERS	"cspdiuxX%"
# define NUMBERS	"0123456789"
# define FLAGS		"-0.# +"
# define ISNULL		"(null)"

typedef struct s_flags
{
	int	minus;
	int	minus_len;
	int	zero;
	int	just_num;
	int	zero_len;
	int	dot;
	int	dot_len;
	int	hash;
	int	space;
	int	plus;
}				t_flags;

int		print_char(char c);
int		print_string(char *str);
t_flags	set_flags_init(void);
int		address_len(unsigned long num);
int		ft_printf(const char *format, ...);
int		print_char_handler(char c, t_flags flags);
int		print_num_handler(int num, t_flags flags);
int		num_handler_flags(int num, t_flags flags);
int		num_handler_flags_plus(int num, t_flags flags);
int		print_string_handler(char *str, t_flags flags);
int		print_address_handler(void *ptr, t_flags flags);
int		print_unum_handler(unsigned int num, t_flags flags);
int		print_hex_handler(unsigned int num, char set, t_flags flags);

#endif
