/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:40:45 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/22 11:34:04 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		print_char(char c);
int		print_string(char *str);
int		ft_printf(const char *format, ...);

#endif
