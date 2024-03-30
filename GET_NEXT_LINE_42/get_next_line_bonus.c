/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/30 09:47:33 by abadouab         ###   ########.fr       */
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
		free(prev->save);
		prev->save = NULL;
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
	free(current->save);
	current->save = NULL;
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

static t_list	*get_next(t_list **head, t_list *node)
{
	size_t	len;
	char	*new;

	if (!node->save || !*node->save)
		return (free_node(head, node->fd), NULL);
	len = strlen_set(node->save, '\n');
	if (node->save[len] == '\n')
		len++;
	new = strdup_set(node->save + len, END);
	if (!new)
		return (free_node(head, node->fd), NULL);
	return (free(node->save), node->save = NULL,
		node->save = new, node);
}

static char	*get_read(t_list *node)
{
	char	*load;
	int		bytes;

	bytes = 1;
	load = malloc((size_t)BUFFER_SIZE + 1);
	if (!load)
		return (free(node->save), node->save = NULL, NULL);
	while (ft_search(node->save) && bytes)
	{
		bytes = read(node->fd, load, BUFFER_SIZE);
		if (bytes == -1)
			return (free(load), NULL);
		load[bytes] = END;
		node->save = ft_strjoin(node->save, load);
	}
	return (free(load), node->save);
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
		return (NULL);
	current->save = get_read(current);
	line = strdup_set(current->save, NLN);
	if (!line)
		return (free_node(&save, fd), NULL);
	return (current = get_next(&save, current), line);
}
