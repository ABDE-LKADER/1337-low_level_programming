/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/14 14:55:43 by abadouab         ###   ########.fr       */
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

	for (int i = 0; i < len / 2; i++)
		middle = middle->next;

	for (int i = 0; i < len - 1; i++)
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

void	sort_stack(t_stack	**stack_a, t_stack	**stack_b)
{
	int	len;
	int	pivot;

	len = size_stack(*stack_a);
	if (len == 1)
		exit(EXIT_SUCCESS);
	pivot = find_pivot(*stack_a, len);
	if ((*stack_a)->value < pivot)
		pb(stack_a, stack_b);
	else
		ra(stack_a, 1);
	sort_stack(stack_a, stack_b);
	sort_stack(stack_b, stack_a);
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
