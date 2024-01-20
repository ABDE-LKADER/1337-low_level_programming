/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/18 21:18:41 by abadouab         ###   ########.fr       */
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

void	sort_less(t_stack **stack_a)
{
	int	one;
	int	tow;
	int	three;

	one = (*stack_a)->value;
	tow = (*stack_a)->next->value;
	three = (*stack_a)->next->next->value;
	if (one > tow && tow > three)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (one < three && three < tow)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (one > three && three > tow)
		ra(stack_a, 1);
	else if (one < three && three > tow)
		sa(stack_a, 1);
	else if (one > three && three < tow)
		rra(stack_a, 1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = size_stack(*stack_a);
	if (len == 2)
		sa(stack_a, 1);
	else if (len == 3)
		sort_less(stack_a);
	(void)stack_b;
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
	sleep(100);
	return (EXIT_SUCCESS);
}
