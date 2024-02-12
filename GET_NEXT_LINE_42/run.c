#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main ()
{
	int fd = open("file.txt", O_RDONLY);
	// char    *line = get_next_line(fd);
	char    *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
 	fd = -1;
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	printf("%s", line = get_next_line(fd));
	free(line);
	// printf("%s", line = get_next_line(fd));
	// printf("%s", line = get_next_line(fd));
	// printf("%s", line = get_next_line(fd));
	// printf("%s", line = get_next_line(fd));
}
