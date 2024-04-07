/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/07 10:51:46 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_hex(unsigned int num, char set, t_flags flags)
{
	int		len;
	char	*base;

	len = 0;
	base = NULL;
	if (!num && flags.dot && !flags.dot_len)
		return (0);
	if (set == 'x')
		base = "0123456789abcdef";
	else if (set == 'X')
		base = "0123456789ABCDEF";
	if (num > 15)
		len += print_hex(num / 16, set, flags);
	len += print_char(base[num % 16]);
	return (len);
}

static int	hex_handler_zero(unsigned int num, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.dot_len > hex_len(num, flags) && flags.hash && num
		&& (flags.zero || flags.just_num) && flags.dot)
		flags.zero_len -= flags.dot_len + 2;
	else if (flags.dot_len > hex_len(num, flags) && flags.dot
		&& (flags.zero || flags.just_num))
		flags.zero_len -= flags.dot_len;
	else if ((flags.zero || flags.just_num) && flags.hash && num)
		flags.zero_len -= hex_len(num, flags) + 2;
	else if (flags.zero || flags.just_num)
		flags.zero_len -= hex_len(num, flags);
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

static int	hex_handler_hash(unsigned int num, char set, t_flags *flags)
{
	int	print;

	print = 0;
	if ((flags->hash && !flags->dot && !flags->zero && !flags->just_num
			&& num && set == 'x') || (flags->hash && !flags->dot
			&& !flags->just_num && num && set == 'x'))
		print += print_string("0x");
	else if ((flags->hash && !flags->dot && !flags->zero
			&& !flags->just_num && num && set == 'X') || (flags->hash
			&& !flags->dot && !flags->just_num && num && set == 'X'))
		print += print_string("0X");
	print += hex_handler_zero(num, *flags);
	if (flags->hash && flags->dot && num && set == 'x')
		print += print_string("0x");
	else if (flags->hash && flags->dot && num && set == 'X')
		print += print_string("0X");
	if (flags->hash && !flags->dot
		&& (flags->just_num) && num && set == 'x')
		print += print_string("0x");
	else if (flags->hash && !flags->dot
		&& (flags->just_num) && num && set == 'X')
		print += print_string("0X");
	return (print);
}

static int	hex_handler_plus(unsigned int num, char set, t_flags *flags)
{
	int	print;

	print = hex_handler_hash(num, set, flags);
	if (flags->dot_len > hex_len(num, *flags) && num && flags->minus
		&& flags->hash && flags->dot)
		flags->minus_len -= flags->dot_len + 2;
	else if (flags->dot_len > hex_len(num, *flags) && flags->minus
		&& flags->dot)
		flags->minus_len -= flags->dot_len;
	else if (flags->minus && flags->hash && num)
		flags->minus_len -= hex_len(num, *flags) + 2;
	else if (flags->minus)
		flags->minus_len -= hex_len(num, *flags);
	return (print);
}

int	print_hex_handler(unsigned int num, char set, t_flags flags)
{
	int	print;

	print = hex_handler_plus(num, set, &flags);
	if (flags.dot && flags.dot_len)
	{
		if (!num)
			flags.dot_len -= 1;
		flags.dot_len -= hex_len(num, flags);
		while (flags.dot_len-- > 0)
			print += print_char('0');
	}
	print += print_hex(num, set, flags);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
