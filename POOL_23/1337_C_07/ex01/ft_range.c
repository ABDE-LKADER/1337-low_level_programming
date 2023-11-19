/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:06:16 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/29 10:06:18 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*num;

	if (min >= max)
		return (0);
	len = max - min;
	num = (int *) malloc((len + 1) * 4);
	i = 0;
	while (i < len)
	{
		num[i] = min;
		i++;
		min++;
	}
	return (num);
}
