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

int	print_unum(unsigned int num)
{
	int	len;

	len = 0;
	if (num > 9)
		len += print_unum(num / 10);
	len += print_char(num % 10 + 48);
	return (len);
}

int	print_unum_handler(unsigned int num, t_flags flags)
{
	int	print;

	print = 0;
	flags.zero_len -= unum_len(num);
	if (flags.zero)
	{
		while (flags.zero_len-- > 0)
			print += print_char('0');
	}
	flags.dot_len -= unum_len(num);
	if (flags.dot)
	{
		while (flags.dot_len-- > 0)
			print += print_char('0');
	}
	print += print_unum(num);
	flags.minus_len -= unum_len(num);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
