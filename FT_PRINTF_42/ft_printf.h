/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:40:45 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/24 19:20:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_PRINTF
# define LIBFT_PRINTF

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_address(void *ptr);
int		ft_print_base(long num, char set);
int		ft_print_percent(void);
int		ft_printf(const char *format, ...);

#endif
