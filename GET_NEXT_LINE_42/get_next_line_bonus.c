/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/20 15:09:37 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	fd_check(t_list *save, int fd)
{
	while (save->next)
	{
		if (save->fd == fd)
			return (1);
		save = save->next;
	}
	return (0);
}

static void	fd_add(t_list **save, int fd)
{
	t_list	*node;
	t_list	*new;

	if (!save)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->fd = fd;
	new->save = NULL;
	new->next = NULL;
	if (!(*save))
	{
		*save = new;
		return ;
	}
	node = *save;
	while (node->next)
		node = node->next;
	node->next = new;
}

static char	*get_read(int fd, char *save)
{
	char	*load;
	int		bytes;

	bytes = 1;
	load = malloc((size_t)BUFFER_SIZE + 1);
	if (!load)
		return (NULL);
	while (ft_search(save) && bytes)
	{
		bytes = read(fd, load, BUFFER_SIZE);
		if (bytes == -1)
			return (free(load), NULL);
		load[bytes] = '\0';
		save = join_strings(save, load);
	}
	return (free(load), save);
}

char	*get_next_line(int fd)
{
	static t_list	*save = NULL;
	t_list			*tsave;
	char			*line;

	if (!save || !fd_check(save, fd))
		fd_add(&save, fd);
	tsave = save;
	while (tsave->next)
	{
		if (tsave->fd == fd)
			break ;
		tsave = tsave->next;
	}
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, tsave->save, 0) == -1)
		return (NULL);
	tsave->save = get_read(fd, tsave->save);
	if (!tsave->save)
		return (NULL);
	line = strdup_line(tsave->save);
	tsave->save = strdup_next(tsave->save);
	return (line);
}
