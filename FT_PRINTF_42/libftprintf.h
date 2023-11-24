/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:40:45 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 18:50:03 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_PRINTF
# define LIBFT_PRINTF

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		print_char(char c);
int		print_string(char *str);
int		print_address(void *ptr);
int		print_base(long num, char set);
int		print_percent(void);
int		ft_printf(const char *format, ...);

#endif
