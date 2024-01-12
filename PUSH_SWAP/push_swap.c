/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/12 10:58:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	message_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - 48;
		i++;
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			message_error();
	}
	return (num * sign);
}

static void	check_in(int ac, char **av)
{
	int		i;
	int		j;
	char	*check;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!ft_strchr(" -+0123456789", av[i][j])))
				message_error();
			else if (ft_strchr("-+", av[i][j]) && !ft_isdigit(av[i][j + 1]))
				message_error();
			else if (ft_isdigit(av[i][j])
				&& !ft_strchr(" 0123456789", av[i][j + 1]))
				message_error();
			j++;
		}
		check = ft_strtrim(av[i], " ");
		if (!check[0])
			message_error();
		i++;
	}
}

t_stack	*add_num(char *value)
{
	t_stack	*num;

	num = malloc(sizeof(t_stack));
	if (!num)
		return (NULL);
	num->value = ft_atol(value);
	num->next = NULL;
	return (num);
}

static	t_stack	*parce_in(int ac, char **av)
{
	t_stack	*stack;
	char	**spn;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			spn = ft_split(av[i], ' ');
			while (*spn)
			{
				stack = add_num(*spn++);
				printf("%d\n", stack->value);
				stack = stack->next;
			}
		}
		else
			stack = add_num(av[i]);
		printf("%d\n", stack->value);
		stack = stack->next;
		i++;
	}
	stack->next = NULL;
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 1)
		return (EXIT_SUCCESS);
	check_in(ac, av);
	stack_a = parce_in(ac, av);
	return (EXIT_SUCCESS);
}
