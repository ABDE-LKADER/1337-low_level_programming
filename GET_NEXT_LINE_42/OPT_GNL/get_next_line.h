/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:39:33 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/16 16:02:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>
#include <fcntl.h>

int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2, int lens2);
char	*get_next_line(int fd);

#endif
