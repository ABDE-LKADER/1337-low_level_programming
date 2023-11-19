/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:49:40 by abadouab          #+#    #+#             */
/*   Updated: 2023/10/05 17:49:41 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char sep, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == sep)
			return (1);
		i++;
	}
	if (sep == '\0')
		return (1);
	return (0);
}

void	set_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (check_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split_str(char	**dest, char *str, char *charset)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep(str[i + j], charset) == 0)
				j++;
			dest[w] = (char *)malloc(sizeof(char *) * (j + 1));
			set_word(dest[w], str + i, charset);
			i += j;
			w++;
		}
	}
}

int	words_counter(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], charset) == 0
			&& check_sep(str[i + 1], charset) == 1)
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		num;

	num = words_counter(str, charset);
	dest = (char **)malloc(sizeof(char *) * (num + 1));
	split_str(dest, str, charset);
	dest[num] = 0;
	return (dest);
}
