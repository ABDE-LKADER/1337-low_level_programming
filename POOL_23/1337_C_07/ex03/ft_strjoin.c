/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:06:39 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/29 10:06:40 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	while (dest[len] != '\0')
		len++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

int	_total_len(int size, char **strs, char *sep)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += _strlen(strs[i]);
		if (i < size - 1)
			len += _strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*dest;

	if (size <= 0)
	{
		dest = malloc(1);
		return (dest);
	}
	len = _total_len(size, strs, sep);
	dest = (char *) malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	dest[0] = '\0';
	while (i < size)
	{
		_strcat(dest, strs[i]);
		if (i < size - 1)
			_strcat(dest, sep);
		i++;
	}
	return (dest);
}
