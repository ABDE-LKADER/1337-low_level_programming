/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:06:27 by abadouab          #+#    #+#             */
/*   Updated: 2023/10/03 10:06:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	_putnbr(int nb)
{
	unsigned int	num;

	if (nb < 0)
	{
		num = -nb;
		_putchar('-');
	}
	else
		num = nb;
	if (num > 9)
		_putnbr(num / 10);
	_putchar(num % 10 + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		_putstr(par[i].str);
		_putchar('\n');
		_putnbr(par[i].size);
		_putchar('\n');
		_putstr(par[i].copy);
		_putchar('\n');
		i++;
	}
}
