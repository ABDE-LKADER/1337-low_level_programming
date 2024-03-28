/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_NLN.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 10:57:08 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_NLN(-1);
	printf("%s", line);
	free(line);
	line = get_next_NLN(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_NLN(fd);
	}
	line = get_next_NLN(fd);
	printf("%s", line);
	free(line);
	line = get_next_NLN(fd);
	printf("%s", line);
	free(line);
	line = get_next_NLN(fd);
	printf("%s", line);
	free(line);
}
