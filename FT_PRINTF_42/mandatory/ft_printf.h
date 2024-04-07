/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:31:09 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/07 10:48:50 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../MYLIB/mylib.h"
# include <unistd.h>
# include <stdarg.h>

# define SPECIFIERS	"cspdiuxX%"

int	print_char(char c);
int	print_num(int num);
int	print_string(char *str);
int	print_address(void *ptr);
int	print_unum(unsigned int num);
int	print_hex(unsigned int num, char set);
int	ft_printf(const char *format, ...);

#endif
