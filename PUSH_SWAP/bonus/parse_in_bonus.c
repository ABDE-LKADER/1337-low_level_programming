/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/18 22:04:57 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	free_stack(t_stack *stack)
{
	t_stack *loop;

	if (!stack)
		return ;
	while (stack)
	{
		loop = stack->next;
		free(stack);
		stack = loop;
	}
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

// static void free_mat(char ***mat)
// {
// 	int		i;

// 	i = 0;
// 	while ((*mat)[i])
// 	{
// 		free((*mat)[i]);
// 		i++;
// 	}
// 	free(*mat);
// }

t_stack	*parce_in(int ac, char **av)
{
	t_stack	*stack = NULL;
	char	***tmp;
	char	**spn;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			spn = ft_split(av[i], ' ');
			while (spn[j])
			{
				add_num(&stack, spn[j]);
				free(spn[j]);
				j++;
			}
			tmp = &spn;
			free(*tmp);
			// free_mat(&spn);
		}
		else
			add_num(&stack, av[i]);
		i++;
	}
	check_double(stack);
	return (stack);
}
