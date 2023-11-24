/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:20:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
				print += ft_print_char(va_arg(lstarg, int));
			if (format[i] == 's')
				print += ft_print_string(va_arg(lstarg, char *));
			if (format[i] == 'p')
				print += ft_print_address(va_arg(lstarg, void *));
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X')
				print += ft_print_base(va_arg(lstarg, long), format[i]);
			if (format[i] == '%')
				print += ft_print_percent();
		}
		else
			print += ft_print_char(format[i]);
		i++;
	}
	return (va_end(lstarg), print);
}
