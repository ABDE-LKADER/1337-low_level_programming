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
	else if (!flags.minus && !flags.dot && !flags.zero && !flags.just_num && (flags.plus || flags.space) && num < 0)
		print = print_char('-');
	else if (!flags.minus && !flags.dot && !flags.zero && !flags.just_num && flags.plus)
		print = print_char('+');
	else if (!flags.minus && !flags.dot && !flags.zero && !flags.just_num && flags.space)
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
