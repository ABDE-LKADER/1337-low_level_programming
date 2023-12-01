/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:19:43 by abdel             #+#    #+#             */
/*   Updated: 2023/11/29 19:19:57 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	address_plus(unsigned long num, char set)
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
