/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 07:52:24 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 11:04:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_set(char *s, char set)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != set)
		i++;
	return (i);
}

size_t	ft_search(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
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
	if (!str || !*str)
		return (free(str), str = NULL, NULL);
	len = strlen_set(str, '\n');
	if (str[len] == '\n')
		len++;
	new = malloc((strlen_set(str, '\0') - len) + 1);
	if (!new)
		return (free(str), str = NULL, NULL);
	while (str[len])
		new[i++] = str[len++];
	return (new[i] = '\0', free(str), str = NULL, new);
}

char	*strdup_line(char *str, int set)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	if (!str || !*str)
		return (NULL);
	if (set)
		len = strlen_set(str, '\n');
	else
		len = strlen_set(str, '\0');
	if (set && str[len] == '\n')
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	return (new[i] = '\0', new);
}

char	*join_strings(char *save, char *load)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!save)
		return (strdup_line(load, TRUE));
	str = malloc(strlen_set(save, '\0') + strlen_set(load, '\0') + 1);
	if (!str)
		return (free(save), save = NULL, NULL);
	i = 0;
	while (save[i])
	{
		str[i] = save[i];
		i++;
	}
	j = 0;
	while (load[j])
		str[i++] = load[j++];
	return (str[i] = '\0', free(save), save = NULL, str);
}
