/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/27 11:49:56 by abdel            ###   ########.fr       */
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
	len += print_hex((unsigned long)ptr, 'x');
	return (len);
}

int	print_hex(unsigned long num, char set)
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

int	print_percent(void)
{
	return (print_char('%'));
}
