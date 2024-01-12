/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/12 22:21:54 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	check_in(ac, av);
	stack_a = parce_in(ac, av);
	add_num(&stack_b, "1337");
	pa(&stack_a, &stack_b);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	return (EXIT_SUCCESS);
}
