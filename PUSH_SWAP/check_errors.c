/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/13 15:41:08 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
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

void	t_clear(t_stack **lst, void (*del)(void *))
{
	t_stack	*node;
	t_stack	*loop;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		loop = node->next;
		free(node);
		node = loop;
	}
	*lst = NULL;
}

void	check_double(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->value == temp->value)
				message_error();
			temp = temp->next;
		}
		stack = stack->next;
	}
}

void	check_in(int ac, char **av)
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
		if (!*check)
			message_error();
		ft_atol(av[i]);
		i++;
	}
}
