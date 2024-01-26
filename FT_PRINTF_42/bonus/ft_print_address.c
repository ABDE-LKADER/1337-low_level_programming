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

static int	address_plus(unsigned long num, char set)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (num > 15)
		len += address_plus(num / 16, set);
	len += print_char(base[num % 16]);
	return (len);
}

int	print_address(void *ptr)
{
	int	len;

	len = 0;
	len += print_string("0x");
	len += address_plus((unsigned long)ptr, 'x');
	return (len);
}

int	print_address_handler(void *ptr, t_flags flags)
{
	(void)flags;
    return(print_address(ptr));
}
