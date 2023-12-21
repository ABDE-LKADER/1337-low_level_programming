/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:39:30 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/21 15:30:26 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_and_indxline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*shift_buf(char *str, long n)
{
	int	i;

	i = 0;
	if (n == -1)
		n = BUFFER_SIZE;
	while (str[i + n])
	{
		str[i] = str[i + n + 1];
		i++;
	}
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*read_and_set(int fd, char *buffer)
{
	char	*res;
	int		index_nl;

	index_nl = check_and_indxline(buffer);
	res = NULL;
	res = ft_strjoin(res, buffer, index_nl + 1);
	buffer = shift_buf(buffer, index_nl);
	while (index_nl == -1 && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		index_nl = check_and_indxline(buffer);
		res = ft_strjoin(res, buffer, index_nl + 1);
		buffer = shift_buf(buffer, index_nl);
	}
	if (ft_strlen(res) == 0)
	{
		buffer = shift_buf(buffer, -1);
		return (free(res), NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[(unsigned int)BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		shift_buf(buffer, -1);
		return (NULL);
	}
	line = read_and_set(fd, buffer);
	return (line);
}
