/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/29 15:12:59 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_node(t_list **save, int fd)
{
	t_list	*prev;
	t_list	*current;

	if (!save)
		return ;
	prev = *save;
	current = (*save)->next;
	if (prev->fd == fd)
	{
		(*save) = current;
		free(prev);
		prev = NULL;
		return ;
	}
	while (current && current->fd != fd)
	{
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	free(current);
	current = NULL;
}

static void	fd_add(t_list **save, int fd)
{
	t_list	*node;
	t_list	*new;

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

static char	*get_next(char *save)
{
	size_t	len;
	char	*new;

	if (!save || !*save)
		return (free(save), save = NULL, NULL);
	len = strlen_set(save, '\n');
	if (save[len] == '\n')
		len++;
	new = strdup_set(save + len, END);
	if (!new)
		return (free(save), save = NULL, NULL);
	return (free(save), save = NULL, new);
}

static char	*get_read(int fd, char *save)
{
	char	*load;
	int		bytes;

	bytes = 1;
	load = malloc((size_t)BUFFER_SIZE + 1);
	if (!load)
		return (free(save), save = NULL, NULL);
	while (ft_search(save) && bytes)
	{
		bytes = read(fd, load, BUFFER_SIZE);
		if (bytes == -1)
			return (free(load), NULL);
		load[bytes] = END;
		save = ft_strjoin(save, load);
	}
	return (free(load), save);
}

char	*get_next_line(int fd)
{
	static t_list	*save = NULL;
	t_list			*current;
	char			*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!save || !fd_check(save, fd))
		fd_add(&save, fd);
	current = save;
	while (current && current->fd != fd)
		current = current->next;
	if (!current)
		return (free(current), current = NULL, NULL);
	current->save = get_read(fd, current->save);
	line = strdup_set(current->save, NLN);
	if (!line)
		return (free_node(&save, fd), NULL);
	current->save = get_next(current->save);
	if (!current->save)
		free_node(&save, fd);
	return (line);
}
