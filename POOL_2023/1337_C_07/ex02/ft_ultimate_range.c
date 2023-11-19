/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:06:28 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/29 10:06:29 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	*range = (int *) malloc(len * 4);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (len);
}
