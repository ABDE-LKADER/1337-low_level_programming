/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/23 17:52:23 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_char(char c)
{
	return (ft_putchar_fd(c, 1), 1);
}

int		print_string(char *str)
{
	int		i;

	if (!str)
		return (ft_putstr_fd("(null)", 1), 0);
	i = 0;
	while (str[i])
		i++;
	return (ft_putstr_fd(str, 1), i);
}

int		print_x(char *str)
{
	return (1);
}
