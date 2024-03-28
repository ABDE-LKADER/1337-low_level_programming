/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 10:01:36 by abadouab         ###   ########.fr       */
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
	while (current && current->fd != fd)
	{
		prev = prev->next;
		current = current->next;
	}
	prev->next = current->next;
	free(current);
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

static char	*get_next(char *str)
{
	size_t	i;
	size_t	len;
	char	*new;

	if (!str || !*str)
		return (free(str), str = NULL, NULL);
	len = strlen_set(str, '\n');
	if (str[len] == '\n')
		len++;
	new = malloc((strlen_set(str, '\0') - len) + 1);
	if (!new)
		return (free(str), str = NULL, NULL);
	i = 0;
	while (str[len])
		new[i++] = str[len++];
	return (new[i] = '\0', free(str), str = NULL, new);
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
	current->save = get_read(fd, current->save);
	line = ft_strdup(current->save, NLN);
	current->save = get_next(current->save);
	if (!line)
		return (free_node(&save, fd), NULL);
	return (line);
}
