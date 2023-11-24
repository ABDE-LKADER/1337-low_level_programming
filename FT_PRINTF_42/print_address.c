/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:16:23 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:20:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_address(void *ptr)
{
	int		len;

	len = 0;
	len += ft_print_string("0x");
	len += ft_print_base((long)ptr, 'x');
	return (len);
}
