/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/25 11:05:49 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (ft_putchar_fd(c, 1), 1);
}

int	print_string(char *str)
{
	if (!str)
		return (print_string("(null)"));
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

int	print_address(void *ptr)
{
	int		len;

	len = 0;
	len += print_string("0x");
	len += print_base((long long)ptr, 'x');
	return (len);
}

int	print_base(long long num, char set)
{
	int		len;
	char	*base;
	long long	lbase;
	long long	number;

	len = 0;
	base = NULL;
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
		len += print_base(number / lbase, set);
	len += print_char(base[number % lbase]);
	return (len);
}

int	print_percent(void)
{
	return (print_char('%'));
}
