/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:26:54 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		print;
	va_list	lstarg;

	i = 0;
	print = 0;
	va_start(lstarg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				print += print_char(va_arg(lstarg, int));
			if (format[i] == 's')
				print += print_string(va_arg(lstarg, char *));
			if (format[i] == 'p')
				print += print_address(va_arg(lstarg, void *));
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X')
				print += print_base(va_arg(lstarg, long), format[i]);
			if (format[i] == '%')
				print += print_percent();
		}
		else
			print += print_char(format[i]);
		i++;
	}
	return (va_end(lstarg), print);
}

