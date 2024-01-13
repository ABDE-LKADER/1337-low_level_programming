/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/13 13:09:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tests(t_stack *stack_a, t_stack *stack_b)
{
	add_num(&stack_b, "10");
	add_num(&stack_b, "11");
	add_num(&stack_b, "12");
	add_num(&stack_b, "13");
	add_num(&stack_b, "14");
	add_num(&stack_b, "15");
	add_num(&stack_b, "16");
	add_num(&stack_b, "17");
	add_num(&stack_b, "18");
	add_num(&stack_b, "19");
	ft_printf("------ ACTIONS\n");
	rra(&stack_a, 1);
	rrb(&stack_b, 1);
	rrr(&stack_a, &stack_b);
	ft_printf("------ STACK A\n");
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("------ STACK B\n");
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_printf("------/// /// ///\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	check_in(ac, av);
	stack_a = parce_in(ac, av);
	stack_b = NULL;
	tests(stack_a, stack_b);
	return (EXIT_SUCCESS);
}
