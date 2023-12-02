/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:43:50 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/01 19:22:37 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	l;
	unsigned char	*str;

	i = 0;
	l = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == l)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
