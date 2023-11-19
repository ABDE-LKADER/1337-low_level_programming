/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:53:51 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/18 09:53:52 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	ld;
	unsigned int	ls;

	len = 0;
	while (dest[len] != '\0' && len < size)
		len++;
	ld = len;
	ls = _strlen(src);
	if (size > len)
	{
		i = 0;
		while (src[i] != '\0' && len < size - 1)
		{
			dest[len] = src[i];
			len++;
			i++;
		}
		dest[len] = '\0';
	}
	return (ld + ls);
}
