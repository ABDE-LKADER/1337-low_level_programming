/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:26:53 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/28 09:08:03 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# define END '\0'
# define NLN '\n'
# define OPEN_MAX 10240

typedef struct s_list
{
	int				fd;
	char			*save;
	struct s_list	*next;
}	t_list;

size_t	ft_search(char *s);
char	*get_next_line(int fd);
size_t	strlen_set(char *s, char set);
int		fd_check(t_list *save, int fd);
char	*strdup_set(char *str, char set);
char	*ft_strjoin(char *save, char *load);

#endif
