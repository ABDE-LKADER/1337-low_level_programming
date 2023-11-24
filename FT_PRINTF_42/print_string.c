/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:16:11 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:20:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_string(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1), 0);
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}
