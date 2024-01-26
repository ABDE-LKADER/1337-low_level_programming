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

int	print_num(int num)
{
	int				len;
	unsigned int	number;

	len = 0;
	if (num < 0)
	{
		number = -num;
		len += print_char('-');
	}
	else
		number = num;
	if (number > 9)
		len += print_unum(number / 10);
	len += print_char(number % 10 + 48);
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

int	print_num_handler(int num, t_flags flags)
{
	(void)flags;
	return (print_num(num));
}

int	print_unum_handler(unsigned int num, t_flags flags)
{
	(void)flags;
	return (print_unum(num));
}
