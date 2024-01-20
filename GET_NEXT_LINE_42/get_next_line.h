/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:26:53 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/21 18:14:27 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1337
#endif

char	*get_read(int fd, char *next);
size_t	ft_search(char *s);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*strdup_next(char *str);
size_t	strlen_set(char *s, char set);
char	*ft_strjoin(char *s1, char *s2);

#endif
