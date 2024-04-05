/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/05 11:00:33 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_string(char *str)
{
	if (!str)
		str = ISNULL;
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

static void	len_handler_zero(char *str, t_flags *flags)
{
	if (flags->dot && (flags->zero || flags->just_num) && !flags->minus)
	{
		if (!str && flags->dot_len >= ft_strlen(ISNULL))
			flags->zero_len -= ft_strlen(ISNULL);
		else if (str && ft_strlen(str) > flags->dot_len)
			flags->zero_len -= flags->dot_len;
		else if (!str)
			flags->zero_len -= flags->dot_len;
		else if (str)
			flags->zero_len -= ft_strlen(str);
	}
	else if (!str && (flags->zero || flags->just_num) && !flags->minus)
		flags->zero_len -= ft_strlen(ISNULL);
	else if ((flags->zero || flags->just_num) && !flags->minus)
		flags->zero_len -= ft_strlen(str);
}

static int	len_handler_minus(char *str, t_flags *flags)
{
	int	print;

	print = 0;
	if (!str && flags->dot_len >= ft_strlen(ISNULL)
		&& flags->minus && flags->dot)
		flags->minus_len -= ft_strlen(ISNULL);
	else if (!str && flags->minus && flags->dot)
		flags->minus_len -= flags->dot_len;
	else if (str && ft_strlen(str) > flags->dot_len
		&& flags->minus && flags->dot)
		flags->minus_len -= flags->dot_len;
	else if (!str && flags->minus && flags->dot_len)
		flags->minus_len -= ft_strlen(ISNULL);
	else if (!str && flags->minus && !flags->dot)
		flags->minus_len -= ft_strlen(ISNULL);
	else if (str && flags->minus)
		flags->minus_len -= ft_strlen(str);
	return (print);
}

static int	string_handler_zero(char *str, t_flags flags)
{
	int	print;

	print = 0;
	len_handler_zero(str, &flags);
	if ((flags.zero || flags.just_num) && !flags.minus)
	{
		while (flags.zero_len-- > 0)
		{
			if (flags.just_num)
				print += print_char(' ');
			else
				print += print_char('0');
		}
	}
	return (print);
}

int	print_string_handler(char *str, t_flags flags)
{
	int	print;

	print = string_handler_zero(str, flags);
	print += len_handler_minus(str, &flags);
	if (!str && flags.dot_len >= ft_strlen(ISNULL))
		print += print_string(str);
	else if (flags.dot && str)
	{
		while (flags.dot_len-- && *str)
			print += print_char(*str++);
	}
	else if (flags.dot && !str)
	{
		str = ISNULL;
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
