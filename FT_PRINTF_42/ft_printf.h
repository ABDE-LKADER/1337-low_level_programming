/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel <abdel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:31:09 by abadouab          #+#    #+#             */
/*   Updated: 2023/11/29 16:48:26 by abdel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FT_PRINTF
# define LIB_FT_PRINTF

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_char(char c);
int	print_string(char *str);
int	print_address(void *ptr);
int	print_num(int num);
int	print_unum(unsigned int num);
int	print_hex(unsigned int num, char set);
int	ft_printf(const char *format, ...);
int print_percent();

#endif
