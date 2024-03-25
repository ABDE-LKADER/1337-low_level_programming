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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# define OPEN_MAX 10240

typedef struct s_list
{
	int				fd;
	char			*save;
	struct s_list	*next;
}	t_list;

size_t	ft_search(char *s);
char	*get_next_line(int fd);
char	*strdup_line(char *str);
char	*strdup_next(char *str);
size_t	strlen_set(char *s, char set);
char	*join_strings(char *s1, char *s2);

#endif
