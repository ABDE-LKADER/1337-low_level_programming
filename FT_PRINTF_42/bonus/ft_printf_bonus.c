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
#include <stdio.h>

static t_flags set_flags()
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.dot_len = 0;
	flags.zero_len = 0;
	flags.minus_len = 0;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	return (flags);
}

static t_flags	set_flags_len(char *set, t_flags flags)
{
	while (ft_strchr(FLAGS, *set) && ft_strchr(FLAGS, *(set + 1)))
		set++;
	while (*set)
	{
		if (*set == '-')
		{
			if (!flags.minus_len)
				flags.minus_len = ft_atoi(++set);
		}
		else if (ft_strchr("0123456789", *set))
		{
			if (!flags.zero_len)
				flags.zero_len = ft_atoi(set);
		}
		else if (*set == '.')
		{
			if (!flags.dot_len)
				flags.dot_len = ft_atoi(++set);
		}
		set++;
	}
	return (flags);
}

static t_flags	check_flags(char *set, t_flags flags)
{
	flags = set_flags_len(set, flags);
	while (*set)
	{
		if (*set == '-')
			flags.minus = 1;
		else if (*set == '0')
			flags.zero = 1;
		else if (*set == '.')
			flags.dot = 1;
		else if (*set == '#')
			flags.hash = 1;
		else if (*set == ' ')
			flags.space = 1;
		else if (*set == '+')
			flags.plus = 1;
		else if (!flags.minus && !flags.dot && ft_strchr("0123456789", *(set)))
			flags.zero = 1;
		set++;
	}
	return (flags);
}

static int	format_set(char set, va_list lstarg, t_flags flags)
{
	int	print;

	print = 0;
	if (set == 'c')
		print += print_char_handler(va_arg(lstarg, int), flags);
	else if (set == 's')
		print += print_string_handler(va_arg(lstarg, char *), flags);
	else if (set == 'p')
		print += print_address_handler(va_arg(lstarg, void *), flags);
	else if (set == 'd' || set == 'i')
		print += print_num_handler(va_arg(lstarg, int), flags);
	else if (set == 'u')
		print += print_unum_handler(va_arg(lstarg, unsigned int), flags);
	else if (set == 'x' || set == 'X')
		print += print_hex_handler(va_arg(lstarg, unsigned int), set, flags);
	else if (set == '%')
		print += print_char_handler(set, flags);
	return (print);
}

int	ft_printf(const char *format, ...)
{
	int		print;
	t_flags	flags;
	va_list	lstarg;

	print = 0;
	if (!format)
		return (-1);
	va_start(lstarg, format);
	while (*format)
	{
		if (*format != '%')
			print += print_char(*format);
		else if (ft_strchr(SPECIFIERS, *(++format)) || ft_strchr(FLAGS, *format)
			|| ft_strchr(NUMBERS, *format))
		{
			flags = set_flags();
			flags = check_flags((char *)format, flags);
			while (!ft_strchr(SPECIFIERS, *format))
				format++;
			print += format_set(*format, lstarg, flags);
		}
		format++;
	}
	return (va_end(lstarg), print);
}

// int main(void)
// {
// 	printf("LEN: %d\n", ft_printf("MY: %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
// 	printf("LEN: %d\n", printf("OR: %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
// }
