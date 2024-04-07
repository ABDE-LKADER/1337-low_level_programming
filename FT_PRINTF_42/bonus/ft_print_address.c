/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/07 10:54:22 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_address(unsigned long num, char set)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (num > 15)
		len += print_address(num / 16, set);
	len += print_char(base[num % 16]);
	return (len);
}

static void	len_handler_minus(unsigned long ptr, t_flags *flags)
{
	if (flags->dot_len > address_len(ptr) && flags->minus && flags->plus
		&& flags->dot)
		flags->minus_len -= flags->dot_len + 3;
	else if (flags->dot_len > address_len(ptr) && flags->minus && flags->dot)
		flags->minus_len -= flags->dot_len + 2;
	else if (flags->minus && flags->plus)
		flags->minus_len -= address_len(ptr) + 2;
	else if (flags->minus)
		flags->minus_len -= address_len(ptr) + 1;
}

static int	len_handler_zero(unsigned long ptr, t_flags *flags)
{
	int	print;

	print = 0;
	if ((flags->zero || flags->just_num) && flags->plus)
		print += print_string("+0x");
	else if (flags->zero && !flags->dot)
		print += print_string("0x");
	if (flags->dot_len > address_len(ptr) && (flags->zero || flags->just_num)
		&& flags->plus && flags->dot)
		flags->zero_len -= flags->dot_len + 3;
	else if (flags->dot_len > address_len(ptr) && flags->dot
		&& (flags->zero || flags->just_num))
		flags->zero_len -= flags->dot_len + 2;
	else if ((flags->zero && flags->plus)
		|| ((flags->zero || flags->just_num) && flags->dot))
		flags->zero_len -= address_len(ptr) + 2;
	else if (flags->zero || flags->just_num)
		flags->zero_len -= address_len(ptr) + 1;
	return (print);
}

static int	address_handler_zero(unsigned long ptr, t_flags *flags)
{
	int	print;

	print = len_handler_zero(ptr, flags);
	if (flags->zero || flags->just_num)
	{
		while (flags->zero_len-- > 0)
		{
			if (flags->zero && !flags->dot)
				print += print_char('0');
			else
				print += print_char(' ');
		}
	}
	if (!flags->zero && flags->plus)
		print += print_string("+0x");
	else if (!flags->zero || (flags->zero && flags->dot))
		print += print_string("0x");
	len_handler_minus(ptr, flags);
	return (print);
}

int	print_address_handler(void *ptr, t_flags flags)
{
	int	print;

	print = address_handler_zero((unsigned long)ptr, &flags);
	if (flags.dot)
	{
		flags.dot_len -= address_len((unsigned long)ptr) - 1;
		while (flags.dot_len-- > 0)
			print += print_char('0');
	}
	print += print_address((unsigned long)ptr, 'x');
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
