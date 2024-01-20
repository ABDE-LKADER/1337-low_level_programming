/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:26:53 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/20 14:58:13 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char			*ok;
	int				fd;

	fd = open("test.txt", O_RDONLY);
	ok = get_next_line(fd);
	while (ok)
	{
		printf("%s", ok);
		free(ok);
		ok = get_next_line(fd);
	}
	free(ok);
	ok = get_next_line(fd);
	printf("%s", ok);
	free(ok);
	ok = get_next_line(fd);
	printf("%s", ok);
	free(ok);
	ok = get_next_line(fd);
	printf("%s", ok);
	free(ok);
	ok = get_next_line(fd);
	printf("%s", ok);
	free(ok);
}
