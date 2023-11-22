/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:09:41 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/22 15:25:49 by abadouab         ###   ########.fr       */
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

	i = 0;
	if (!str)
		ft_putstr_fd("(null)", 1);
	while (str[i])
		print_char(str[i++]);
	return (i);
}

int		print_(char *)
{
	
}
