/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 07:52:24 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/20 15:12:49 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_set(char *s, char set)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != set)
		i++;
	return (i);
}

size_t ft_search(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*strdup_next(char *str)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	if (!str || !*str) // CHECK
		return (NULL);
	len = strlen_set(str, '\n');
	if (str[len] == '\n')
		len++;
	new = malloc((strlen_set(str, '\0') - len) + 1);
	if (!new)
		return (NULL);
	if (str[len] == '\n')
		len++;
	while (str[len])
		new[i++] = str[len++];
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	if (!str || !*str) // CHECK
		return (NULL);
	len = strlen_set(str, '\n');
	if (str[len] == '\n')
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (s2);
	i = strlen_set(s1, '\0') + strlen_set(s2, '\0');
	printf("%zu\n", i);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	return (str[i] = '\0', str);
}
