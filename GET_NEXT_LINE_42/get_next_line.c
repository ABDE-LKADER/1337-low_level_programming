/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/18 12:39:10 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next(char	*buffer)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
		return (free(buffer), NULL);
	line = ft_calloc(ft_strlen(buffer) - len + 1, sizeof(char));
	len++;
	i = 0;
	while (buffer[len])
		line[i++] = buffer[len++];
	return (free(buffer), line);
}

char	*get_line(char	*buffer)
{
	int		len;
	char	*line;

	len = 0;
	if (!buffer)
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_calloc(len + 1, sizeof(char));
	while (len--)
		line[len] = buffer[len];
	return (line);
}

char	*get_next_line(int fd)
{
	int				bytes;
	char			*new;
	char			*line;
	static char		*buffer;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	bytes = 1;
	new = calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes > 0)
	{
		bytes = read(fd, new, BUFFER_SIZE);
		if (bytes == -1)
			return (free(new), NULL);
		buffer = ft_strjoin(buffer, new);
	}
	return (free(new), line = get_line(buffer),
		buffer = get_next(buffer), line);
}
void f(void){system(leaks run);}
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 30)
	{
		line = get_next_line(fd);
		printf("->>>>> FINAL: %s\n", line);
		i++;
	}
	free(line);
	close(fd);
}
