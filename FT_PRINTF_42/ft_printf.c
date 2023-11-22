/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/22 17:17:35 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		print;
	va_list	lstarg;

	i = 0;
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
				print += print_x(va_arg(lstarg, char *));
			if (format[i] == 'd' || format[i] == 'i')
				print += print_x(va_arg(lstarg, char *));
			if (format[i] == 'u')
				print += print_x(va_arg(lstarg, char *));
			if (format[i] == 'X' || format[i] == 'X')
				print += print_x(va_arg(lstarg, char *));
			if (format[i] == '%')
				print += print_x(va_arg(lstarg, char *));
			}
		else
			print += print_char(format[i]);
		i++;
	}
	return (va_end(lstarg), print);
}
