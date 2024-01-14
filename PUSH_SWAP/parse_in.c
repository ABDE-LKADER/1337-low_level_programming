/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/14 12:36:05 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	size_stack(t_stack *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);	
}

void	add_num(t_stack **stack, char *value)
{
	t_stack	*node;
	t_stack *new;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = ft_atol(value);
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = new;
}

t_stack	*parce_in(int ac, char **av)
{
	t_stack	*stack = NULL;
	char	**spn;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			spn = ft_split(av[i], ' ');
			while (*spn)
				add_num(&stack, *spn++);
		}
		else
			add_num(&stack, av[i]);
		i++;
	}
	check_double(stack);
	return (stack);
}
