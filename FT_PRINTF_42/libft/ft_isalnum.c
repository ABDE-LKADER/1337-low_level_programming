/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:54:37 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/04 21:16:04 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
			|| (c >= 48 && c <= 57)))
		return (0);
	return (1);
}
