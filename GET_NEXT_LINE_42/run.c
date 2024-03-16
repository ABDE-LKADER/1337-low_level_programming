/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:49:53 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/29 16:50:50 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void) {
	// int		fd = open("file.txt", O_RDONLY);
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		printf("line -> %s", line);
	}
}
