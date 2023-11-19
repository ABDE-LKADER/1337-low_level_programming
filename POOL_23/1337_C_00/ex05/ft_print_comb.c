/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:58:38 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/14 12:58:42 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	int_print_char(int one, int tow, int tree)
{
	_putchar(one + 48);
	_putchar(tow + 48);
	_putchar(tree + 48);
	if (one != 7)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	one;
	int	tow;
	int	tree;

	one = 0;
	while (one <= 7)
	{
		tow = one + 1;
		while (tow <= 8)
		{
			tree = tow + 1;
			while (tree <= 9)
			{
				int_print_char(one, tow, tree);
				tree++;
			}
			tow++;
		}
		one++;
	}
}
