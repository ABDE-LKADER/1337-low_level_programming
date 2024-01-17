/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/17 22:46:39 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_back(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

int	find_pivot(t_stack *stack, int len)
{
	t_stack *first = stack;
	t_stack *middle = stack;
	t_stack *last = stack;
	int		i;

	i = 0;
	while (i++ < len / 2)
		middle = middle->next;
	i = 0;
	while (i++ < len - 1)
		last = last->next;
	if ((first->value <= middle->value && middle->value <= last->value) ||
		(last->value <= middle->value && middle->value <= first->value))
		return middle->value;
	else if ((middle->value <= first->value && first->value <= last->value) ||
			 (last->value <= first->value && first->value <= middle->value))
		return first->value;
	else
		return last->value;
}

void	sort_less(t_stack **stack_a, int len)
{
	if (len == 1 || len == 2)
	{
		if (len == 2)
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, 1);
		exit(EXIT_SUCCESS);
	}
	if((*stack_a)->value < (*stack_a)->next->value)
		sa(stack_a, 1);
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
		{
			ra(stack_a, 1);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, 1);
		}
		else if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a, 1);
		else
			ra(stack_a, 1);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	lenb;
	int	pivot;

	len = size_stack(*stack_a);
	lenb = size_stack(*stack_b);
	pivot = find_pivot(*stack_a, len);
	if (len > 3)
	{
		if ((*stack_a)->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		sort_stack(stack_a, stack_b);
	}
	else
		sort_less(stack_a, len);
	sort_back(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac == 1)
		return (EXIT_SUCCESS);
	check_in(ac, av);
	stack_a = parce_in(ac, av);
	if (check_is_sorted(stack_a))
		return (EXIT_SUCCESS);
	sort_stack(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
