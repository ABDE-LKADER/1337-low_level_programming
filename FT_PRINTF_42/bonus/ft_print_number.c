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

static int	number_len(int num)
{
	int	len;
	unsigned int	number;

	len = 1;
	if (num < 0)
	{
		number = -num;
		len++;
	}
	else
		number = num;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	print_num(int num, t_flags flags)
{
	int				len;
	unsigned int	number;

	len = 0;
	if (num < 0)
	{
		number = -num;
		if (!flags.zero && !flags.dot && !flags.plus && !flags.space)
			len += print_char('-');
	}
	else
		number = num;
	if (number > 9)
		len += print_unum(number / 10);
	len += print_char(number % 10 + 48);
	return (len);
}

int	print_num_handler(int num, t_flags flags)
{
	int	print;

	print = 0;
	flags.zero_len -= number_len(num);
	if (flags.zero)
	{
		if (num < 0)
			print += print_char('-');
		while (flags.zero_len-- > 0)
			print += print_char('0');
	}
	if (num < 0)
		flags.dot_len -= number_len(num)  - 1;
	else
		flags.dot_len -= number_len(num);
	if (flags.dot)
	{
		if (num < 0)
			print += print_char('-');
		while (flags.dot_len-- > 0)
			print += print_char('0');
	}
	if (flags.space && num < 0)
			print += print_char('-');
	else if (flags.space)
			print += print_char(' ');
	if (flags.plus && num < 0)
			print += print_char('-');
	else if (flags.plus)
			print += print_char('+');
	print += print_num(num, flags);
	flags.minus_len -= number_len(num);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
