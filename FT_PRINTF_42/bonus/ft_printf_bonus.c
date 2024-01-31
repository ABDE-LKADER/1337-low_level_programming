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

static t_flags	set_flags_init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.minus_len = 0;
	flags.zero = 0;
	flags.just_num = 0;
	flags.zero_len = 0;
	flags.dot = 0;
	flags.dot_len = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

static t_flags	set_flags_len(char *set, t_flags flags)
{
	while (*set && !ft_strchr(SPECIFIERS, *set))
	{
		while (ft_strchr(FLAGS, *set) && ft_strchr(FLAGS, *(set + 1)) && *set == *(set + 1))
			set++;
		if (*set == '-')
		{
			if (!flags.minus_len)
				flags.minus_len = ft_atoi(++set);
		}
		else if (*set == '.')
		{
			if (!flags.dot_len)
				flags.dot_len = ft_atoi(++set);
		}
		else if (ft_isdigit(*set) && !flags.minus_len)
		{
			if (!flags.zero_len)
				flags.zero_len = ft_atoi(set);
		}
		set++;
	}
	return (flags);
}

static t_flags	check_flags(char *set, t_flags flags)
{
	flags = set_flags_init();
	flags = set_flags_len(set, flags);
	while (*set && !ft_strchr(SPECIFIERS, *set))
	{
		while (ft_strchr(FLAGS, *set) && ft_strchr(FLAGS, *(set + 1)) && *set == *(set + 1))
			set++;
		if (*set == '-')
			flags.minus = 1;
		else if (*set == '0' && !flags.minus && !flags.dot && !flags.just_num)
			flags.zero = 1;
		else if (*set == '.')
			flags.dot = 1;
		else if (*set == '#')
			flags.hash = 1;
		else if (*set == ' ')
			flags.space = 1;
		else if (*set == '+')
			flags.plus = 1;
		else if (ft_strchr("123456789", *set) && !flags.minus && !flags.dot && !flags.zero)
			flags.just_num = 1;
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
		print += print_char(set);
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
		if (*format == '%' && (ft_strchr(SPECIFIERS, *(format + 1))
			|| ft_strchr(FLAGS, *(format + 1)) || ft_isdigit(*(format + 1))))
		{
			if (!*(++format))
				return (-1);
			flags = check_flags((char *)format, flags);
			while (!ft_strchr(SPECIFIERS, *format))
				format++;
			print += format_set(*format, lstarg, flags);
		}
		else
			print += print_char(*format);
		format++;
	}
	return (va_end(lstarg), print);
}

int main()
{
	printf("LEN: %d\n", ft_printf("MY: -> %# +100d ", 1231230));
	printf("LEN: %d\n", printf("OR: -> %# +100d ", 1231230));
	// printf("LEN: %d\n", ft_printf("MY: ->  Or:\tChar [%-20.20c] "));
	// printf("LEN: %d\n", printf("OR: ->  Or:\tChar [%-20.20c] "));
}
