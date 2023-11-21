/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/21 09:12:18 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next(char	*buffer)
{
	int 	i;
	int		len;
	char	*line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	len += 1;
	line =  ft_calloc(ft_strlen(buffer) - len, sizeof(char));
	i = 0;
	while (buffer[len])
		line[i++] = buffer[len++];
	free(buffer);
	return (line);
}

char	*get_line(char	*buffer)
{
	int		len;
	char	*line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_calloc(len + 1, sizeof(char));
	while (len--)
		line[len] = buffer[len];
	return (line);	
}

char	*read_bytes(int	fd, char *buffer)
{
	int		bytes;
	char	*new;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	bytes = 1;
	new = calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes > 0)
	{
		bytes = read(fd, new, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(new);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, new);
	}
	free(new);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;

	buffer = read_bytes(fd, buffer);
	line = get_line(buffer);
	buffer = get_next(buffer);
	return (line);
}

int main()
{
	int		i;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("->>>>> FINAL: %s\n", line);
		i;
	}
	printf("->>>>> NUMBER: %d\n", i);
	free(line);
	close(fd);
}
