/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/20 14:01:05 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_line(char	*buffer)
{
	int		len;
	char	*line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	return (line);	
}

char	*read_bytes(int	fd, char *buffer)
{
	int		bytes;
	int		o;
	char	*new;

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
	int			index;
	char		*line;
	char		*buffer;
	
	buffer = read_bytes(fd, buffer);
	line = get_line(buffer);
	// printf("\n->>>>> LINE_0: %s\n", buffer);
	return (line);
}

int main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("\n\n\n->>>>> FINAL: %s\n", line);
	// line = get_next_line(fd);
	// printf("->>>>> LINE: %s\n", line);
	// line = get_next_line(fd);
	// printf("->>>>> LINE: %s\n", line);
	// line = get_next_line(fd);
	// printf("->>>>> LINE: %s\n", line);
	// line = get_next_line(fd);
	// printf("->>>>> LINE: %s\n", line);
	// line = get_next_line(fd);
	// printf("->>>>> LINE: %s\n", line);
	// line = get_next_line(fd);
	// printf("->>>>> LINE: %s\n", line);
	// free(line);
	close(fd);
}
