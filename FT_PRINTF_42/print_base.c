/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:16:20 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:20:16 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_base(long num, char set)
{
	int				len;
	char			*base;
	unsigned long	lbase;
	unsigned long	number;

	len = 0;
	base = NULL;
	if (num < 0 && set != 'u')
	{
		number = -num;
		len += ft_print_char('-');
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
		ft_print_base(number / lbase, set);
	ft_print_char(base[number % lbase]);
	return (len);
}
