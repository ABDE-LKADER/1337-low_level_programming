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

int	print_hex(unsigned int num, char set)
{
	int		len;
	char	*base;

	len = 0;
	base = NULL;
	if (set == 'x')
		base = "0123456789abcdef";
	else if (set == 'X')
		base = "0123456789ABCDEF";
	if (num > 15)
		len += print_hex(num / 16, set);
	len += print_char(base[num % 16]);
	return (len);
}

int	print_hex_handler(unsigned int num, char set, t_flags flags)
{
	(void)flags;
    return(print_hex(num, set));
}
