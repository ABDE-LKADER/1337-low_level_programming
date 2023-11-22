/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:40:45 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/22 17:03:31 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF
# define FT_PRINTF

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		print_char(char c);
int		print_string(char *str);
int		print_x(char *str);
int		ft_printf(const char *format, ...);

#endif
