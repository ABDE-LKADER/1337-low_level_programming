/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:04:09 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/20 08:04:12 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_putchar(char c)
{
	write (1, &c, 1);
}

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	check_doubles(char *str, char c, int p)
{
	int	i;

	i = 0;
	while (i < p)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_base(char *base)
{
	int	i;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] < 32 || base[i] == 127)
			|| check_doubles(base, base[i], i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	lbase;
	unsigned int	num;

	lbase = _strlen(base);
	if (check_base(base) != 0)
	{
		if (nbr < 0)
		{
			_putchar('-');
			num = -nbr;
		}
		else
			num = nbr;
		if (num > lbase - 1)
			ft_putnbr_base(num / lbase, base);
		_putchar(base[num % lbase]);
	}
}
