/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:26:53 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/21 06:53:06 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char    *ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
