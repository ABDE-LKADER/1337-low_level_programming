/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/05 07:44:19 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	address_len(unsigned long num)
{
	int	len;

	len = 2;
	while (num > 15)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	hex_len(unsigned int num, t_flags flags)
{
	int	len;

	if (!num && flags.dot)
		return (0);
	len = 1;
	while (num > 15)
	{
		num /= 16;
		len++;
	}
	return (len);
}

t_flags	set_flags_init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.minus_len = 0;
	flags.zero = 0;
	flags.just_num = 0;
	flags.zero_len = 0;
	flags.dot = 0;
	flags.dot_len = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

int	num_handler_flags(int num, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.minus && num < 0)
		print = print_char('-');
	else if (flags.minus && flags.plus)
		print = print_char('+');
	else if (flags.minus && flags.space)
		print = print_char(' ');
	else if (flags.zero && !flags.dot && num < 0)
		print = print_char('-');
	else if (flags.zero && !flags.dot && flags.plus)
		print = print_char('+');
	else if (flags.zero && !flags.dot && flags.space)
		print = print_char(' ');
	else if (!flags.minus && !flags.dot && !flags.zero && !flags.just_num
		&& (flags.plus || flags.space) && num < 0)
		print = print_char('-');
	else if (!flags.minus && !flags.dot && !flags.zero && !flags.just_num
		&& flags.plus)
		print = print_char('+');
	else if (!flags.minus && !flags.dot && !flags.zero
		&& !flags.just_num && flags.space)
		print = print_char(' ');
	return (print);
}

int	num_handler_flags_plus(int num, t_flags flags)
{
	int	print;

	print = 0;
	if (flags.just_num && num < 0)
		print = print_char('-');
	else if (flags.just_num && flags.plus)
		print = print_char('+');
	else if (flags.just_num && flags.space)
		print = print_char(' ');
	else if (flags.zero && flags.dot && num < 0)
		print = print_char('-');
	else if (flags.zero && flags.dot && flags.plus)
		print = print_char('+');
	else if (flags.zero && flags.dot && flags.space)
		print = print_char(' ');
	else if (flags.dot && !flags.minus && num < 0)
		print = print_char('-');
	else if (flags.dot && !flags.minus && flags.plus)
		print = print_char('+');
	else if (flags.dot && !flags.minus && flags.space)
		print = print_char(' ');
	return (print);
}
