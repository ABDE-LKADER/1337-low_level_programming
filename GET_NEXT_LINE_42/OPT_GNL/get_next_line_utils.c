/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:39:29 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/16 02:39:30 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int lens2)
{
	int		i;
	int		j;
	char	*p;
	int		len;
	int		lens1;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	lens1 = ft_strlen((char *)s1);
	if (lens2 == 0)
		lens2 = ft_strlen((char *)s2);
	len = lens1 + lens2;
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (free((char *)s1), NULL);
	while (s1 && s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2 && i < lens2)
		p[j++] = s2[i++];
	p[j] = '\0';
	return (free((char *)s1), p);
}
