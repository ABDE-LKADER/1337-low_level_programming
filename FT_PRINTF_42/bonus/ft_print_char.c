/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:30:47 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/07 10:52:06 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(char c)
{
	return (ft_putchar_fd(c, 1), 1);
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
