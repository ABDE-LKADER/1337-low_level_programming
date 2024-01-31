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
		str = ISNULL;
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

int	print_char_handler(char c, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.zero || flags.just_num)
	{
		flags.zero_len -= 1;
		while (flags.zero_len-- > 0)
			print += print_char(' ');
	}
	print += print_char(c);
	if (flags.minus)
	{
		flags.minus_len -= 1;
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}

static int	string_handler_plus(char *str, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.dot && (flags.zero || flags.just_num) && !flags.minus)
	{
		if (!str && flags.dot_len >= ft_strlen(ISNULL))
			flags.zero_len -= ft_strlen(ISNULL);
		else if (str && ft_strlen(str) > flags.dot_len)
			flags.zero_len -= flags.dot_len;
		else if (str)
			flags.zero_len -= ft_strlen(str);
	}
	else if ((flags.zero || flags.just_num) && !flags.minus)
		flags.zero_len -= ft_strlen(str);
	if ((flags.zero || flags.just_num) && !flags.minus)
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
	if (!str && flags.dot_len >= ft_strlen(ISNULL) && flags.minus && flags.dot)
		flags.minus_len -= ft_strlen(ISNULL);
	else if (str &&  ft_strlen(str) > flags.dot_len && flags.minus && flags.dot)
		flags.minus_len -= flags.dot_len;
	else if (str && flags.minus)
		flags.minus_len -= ft_strlen(str);
	if (!str && flags.dot_len >= ft_strlen(ISNULL))
		print += print_string(str);
	else if (flags.dot && str)
	{
		while (flags.dot_len-- && *str)
			print += print_char(*str++);
	}
	else if (!flags.dot)
		print += print_string(str);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
