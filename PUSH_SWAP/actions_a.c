/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:56 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/12 22:24:42 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	t_stack	*temp;

	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_printf("sb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	new = *stack_b;
	*stack_b = (*stack_b)->next;
	new->next = *stack_a;
	*stack_a = new;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*new;

	new = *stack_a;
	*stack_a = (*stack_a)->next;
	new->next = *stack_b;
	*stack_b = new;
	ft_printf("pa\n");
}