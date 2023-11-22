/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:30 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/22 15:00:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		print;
	va_list	lstarg;

	i = -1;
	va_start(lstarg, format);
	while (format[i++])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				print += print_char(va_arg(lstarg, int));
			if (format[i] == 's')
				print += print_string(va_arg(lstarg, char *));
		}
		else
			print += print_char(format[i]);
	}
	va_end(lstarg);
	return (print);
}

#include <stdio.h>
int		main(void)
{
	ft_printf("%c \n", 'h');
	printf("%c \n", 'h');
}
