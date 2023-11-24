/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:37:15 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(char c)
{
	return (ft_putchar_fd(c, 1), 1);
}

int	print_string(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1), 0);
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

int	print_address(void *ptr)
{
	int		len;

	len = 0;
	len += print_string("0x");
	len += print_base((long)ptr, 'x');
	return (len);
}

int	print_base(long num, char set)
{
	int				len;
	char			*base;
	unsigned long	lbase;
	unsigned long	number;

	len = 0;
	if (num < 0 && set != 'u')
	{
		number = -num;
		len += print_char('-');
	}
	else
		number = num;
	if (set == 'd' || set == 'i' || set == 'u')
		base = "0123456789";
	else if (set == 'x')
		base = "0123456789abcdef";
	else if (set == 'X')
		base = "0123456789ABCDEF";
	lbase = ft_strlen(base);
	if (number > lbase - 1)
		print_base(number / lbase, set);
	print_char(base[number % lbase]);
	return (len);
}

int	print_percent(void)
{
	return (print_char('%'));
}
