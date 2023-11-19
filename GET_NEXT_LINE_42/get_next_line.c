/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/19 09:44:19 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*list;

	list = calloc(BUFFER_SIZE + 1, sizeof(char));
	
	return (str);
}

int main()
{
	int	fd;
	char	*buffer;

	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("LINE: %s", buffer);
}
