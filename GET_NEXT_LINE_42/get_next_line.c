/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/22 13:11:29 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_read(int fd, char *next)
{
	int			bytes;
	char		*load;

	bytes = 1;
	load = malloc((size_t)BUFFER_SIZE + 1);
	while (ft_search(load) && bytes)
	{
		bytes = read(fd, load, BUFFER_SIZE);
		if (bytes == -1)
			return (free(load), NULL);
		load[bytes] = '\0';
		next = ft_strjoin(next, load);
	}
	free(load);
	return (next);
}

char	*get_next_line(int fd)
{
	int			len;
	char		temp[123123];
	char		*line;
	static char	*next = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || read(fd, line, 0) == -1)
		return (NULL);
	next = get_read(fd, next);
	if (!next)
		return (NULL);
	len = strlen_set(next, '\n');
	line = dup_cpy(line, next, len);
	int i = 0;
	while (next[len])
		temp[i++] = next[len++];
	// free(next);
	return (line);
}
