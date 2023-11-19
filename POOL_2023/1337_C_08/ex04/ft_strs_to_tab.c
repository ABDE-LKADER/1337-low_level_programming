/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:06:12 by abadouab          #+#    #+#             */
/*   Updated: 2023/10/03 10:06:13 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = _strlen(src);
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*st;

	st = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (st == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		st[i].size = _strlen(av[i]);
		st[i].str = av[i];
		st[i].copy = _strdup(av[i]);
		i++;
	}
	st[i].str = 0;
	st[i].copy = 0;
	return (st);
}
