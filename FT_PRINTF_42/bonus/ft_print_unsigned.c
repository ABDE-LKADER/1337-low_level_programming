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

static int	unum_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	print_unum(unsigned int num, t_flags flags)
{
	int	len;

	if (!num && flags.dot && !flags.dot_len)
		return (0);
	len = 0;
	if (num > 9)
		len += print_unum(num / 10, flags);
	len += print_char(num % 10 + 48);
	return (len);
}

static int	unum_handler_plus(unsigned int num, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.dot_len > unum_len(num)
		&& (flags.zero || flags.just_num) && flags.dot)
		flags.zero_len -= flags.dot_len;
	else if (flags.zero || flags.just_num)
	{
		if (!flags.dot_len && flags.dot && !num)
			flags.zero_len += 1;
		flags.zero_len -= unum_len(num);
	}
	if (flags.zero || flags.just_num)
	{
		while (flags.zero_len-- > 0)
		{
			if (flags.just_num || flags.dot)
				print += print_char(' ');
			else
				print += print_char('0');
		}
	}
	return (print);
}

int	print_unum_handler(unsigned int num, t_flags flags)
{
	int	print;

	print = unum_handler_plus(num, flags);
	if (flags.dot_len > unum_len(num) && flags.minus && flags.dot)
		flags.minus_len -= flags.dot_len;
	else if (flags.minus)
	{
		if (!num && flags.dot && !flags.dot_len)
			flags.minus_len += 1;
		flags.minus_len -= unum_len(num);
	}
	if (flags.dot && flags.dot_len)
	{
		flags.dot_len -= unum_len(num);
		while (flags.dot_len-- > 0)
			print += print_char('0');
	}
	print += print_unum(num, flags);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
