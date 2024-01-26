/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/01 17:59:08 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(char c)
{
	return (ft_putchar_fd(c, 1), 1);
}

int	print_string(char *str)
{
	if (!str)
		str = "(null)";
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

int	print_char_handler(char c, t_flags flags)
{
	int	print;

	flags.minus_len -= 1;
	print = print_char(c);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}

static int	string_handler_plus(char *str, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.dot)
		flags.zero_len -= flags.dot_len;
	else
		flags.zero_len -= ft_strlen(str);
	if (flags.zero)
	{
		while (flags.zero_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}

int	print_string_handler(char *str, t_flags flags)
{
	int	print;

	print = string_handler_plus(str, flags);
	if (flags.dot)
	{
		while (flags.dot_len-- && *str)
			print += print_char(*str++);
	}
	else
		print += print_string(str);
	flags.minus_len -= ft_strlen(str);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
