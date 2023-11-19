/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:29:36 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/14 14:29:41 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	int_print_char(int one, int tow)
{
	_putchar(one / 10 + 48);
	_putchar(one % 10 + 48);
	_putchar(' ');
	_putchar(tow / 10 + 48);
	_putchar(tow % 10 + 48);
	if (one != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	one;
	int	tow;

	one = 0;
	while (one <= 98)
	{
		tow = one + 1;
		while (tow <= 99)
		{
			int_print_char(one, tow);
			tow++;
		}
		one++;
	}
}
