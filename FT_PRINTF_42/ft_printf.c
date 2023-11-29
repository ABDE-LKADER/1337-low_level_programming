/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/29 14:47:43 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	format_set(char format, va_list lstarg)
{
	int	print;
	
	print = 0;
	if (format == 'c')
		print += print_char(va_arg(lstarg, int));
	else if (format == 's')
		print += print_string(va_arg(lstarg, char *));
	else if (format == 'p')
		print += print_address(va_arg(lstarg, void *));
	else if (format == 'd' || format == 'i')
		print += print_num(va_arg(lstarg, int));
	else if (format == 'u')
		print += print_unum(va_arg(lstarg, unsigned int));
	else if (format == 'x' || format == 'X')
		print += print_hex(va_arg(lstarg, unsigned long), format);
	else if (format == '%')
		print += print_char('%');
	// printf("FIRST %d\t", print);
	return (print);
}

int	ft_printf(const char *format, ...)
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
			if (ft_strchr("cspdiuxX%", format[i]))
				print += format_set(format[i], lstarg);
		}
		else
			print += print_char(format[i]);
		i++;
	}
	return (va_end(lstarg), print);
}
