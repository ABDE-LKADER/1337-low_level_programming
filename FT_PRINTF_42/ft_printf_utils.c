/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/29 20:00:38 by abdel            ###   ########.fr       */
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

// int print_padding(int zero_pad, int content_len, char pad_char, int *flags)
// {
//     int len = 0;

//     while (flags['-'] == 0 && flags['0'] && zero_pad > content_len)
//     {
//         ft_putchar_fd(pad_char, 1);
//         len++;
//         zero_pad--;
//     }
//     return (len);
// }
