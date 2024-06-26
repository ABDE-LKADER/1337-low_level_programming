/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/07 10:53:39 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	number_len(int num)
{
	int				len;
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

static int	print_num(int num, t_flags flags)
{
	int				len;
	unsigned int	number;

	len = 0;
	if (num < 0)
	{
		number = -num;
		if (!flags.minus && !flags.dot && !flags.zero && !flags.just_num
			&& !flags.plus && !flags.space)
			len += print_char('-');
	}
	else
		number = num;
	if (!num && flags.dot && !flags.dot_len
		&& (!flags.minus || !flags.just_num))
		return (len);
	if (number > 9)
		len += print_num(number / 10, flags);
	len += print_char(number % 10 + 48);
	return (len);
}

static void	zero_len_handler(int num, t_flags *flags)
{
	if (flags->dot_len > number_len(num) && (flags->zero || flags->just_num)
		&& flags->dot)
	{
		(num < 0 || flags->space || flags->plus) && (flags->zero_len -= 1);
		flags->zero_len -= flags->dot_len;
	}
	else if (flags->zero || flags->just_num)
	{
		if ((flags->space && num >= 0) || (!num && flags->plus))
			flags->zero_len -= 1;
		if (num < 0 && flags->dot_len >= number_len(num))
			flags->zero_len -= 1;
		if (num && !flags->minus && !flags->plus)
			flags->zero_len -= number_len(num);
		else if (num > 0 && !flags->dot)
			flags->zero_len -= number_len(num) + 1;
		else if (!flags->dot && !flags->minus)
			flags->zero_len -= number_len(num);
		else if (!num && flags->dot_len == 1)
			flags->zero_len -= number_len(num);
		else if (num > 0 && flags->plus && flags->dot)
			flags->zero_len -= number_len(num) + 1;
		else if (num < 0 && flags->plus && flags->dot)
			flags->zero_len -= number_len(num);
	}
}

static int	num_handler_plus(int num, t_flags flags)
{
	int	print;

	print = num_handler_flags(num, flags);
	zero_len_handler(num, &flags);
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
	print += num_handler_flags_plus(num, flags);
	if (flags.dot && num < 0)
		flags.dot_len -= number_len(num) - 1;
	else if (flags.dot)
		flags.dot_len -= number_len(num);
	if (flags.dot)
	{
		while (flags.dot_len-- > 0)
			print += print_char('0');
	}
	return (print);
}

int	print_num_handler(int num, t_flags flags)
{
	int	print;

	print = num_handler_plus(num, flags);
	if (flags.dot_len > number_len(num) && flags.dot && flags.minus)
	{
		if (num < 0 || flags.space || flags.plus)
			flags.minus_len -= 1;
		flags.minus_len -= flags.dot_len;
	}
	else if (flags.minus)
	{
		(((flags.space || flags.plus) && num >= 0)
			|| (!num && flags.dot_len == 1)) && (flags.minus_len -= 1);
		((num < 0 && flags.dot_len >= number_len(num)) || (!num && (flags.space \
			|| flags.plus) && flags.dot_len == 1)) && (flags.minus_len -= 1);
		((num && flags.dot) || !flags.dot)
			&& (flags.minus_len -= number_len(num));
	}
	print += print_num(num, flags);
	if (flags.minus)
	{
		while (flags.minus_len-- > 0)
			print += print_char(' ');
	}
	return (print);
}
