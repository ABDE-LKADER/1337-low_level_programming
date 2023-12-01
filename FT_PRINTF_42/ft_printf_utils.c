/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/01 19:25:42 by abadouab         ###   ########.fr       */
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
		str = "(null)";
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

static int	address_plus(unsigned long num, char set)
{
	int				len;
	char			*base;

	len = 0;
	base = "0123456789abcdef";
	if (num > 16)
		len += address_plus(num / 16, set);
	len += print_char(base[num % 16]);
	return (len);
}

int	print_address(void *ptr)
{
	int		len;

	len = 0;
	len += print_string("0x");
	len += address_plus((unsigned long)ptr, 'x');
	return (len);
}

int	print_num(int num)
{
	int	len;
	unsigned int number;

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

int	print_hex(unsigned int num, char set)
{
	int				len;
	char			*base;

	len = 0;
	base = NULL;
	if (set == 'x')
		base = "0123456789abcdef";
	else if (set == 'X')
		base = "0123456789ABCDEF";
	if (num > 16)
		len += print_hex(num / 16, set);
	len += print_char(base[num % 16]);
	return (len);
}
