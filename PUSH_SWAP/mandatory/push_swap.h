/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:34 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/18 15:22:23 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

# include "../MYLIB/mylib.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	message_error(void);
long	ft_atol(const char *str);
void	check_in(int ac, char **av);
void	check_double(t_stack *stack);
int		check_is_sorted(t_stack *stack);

size_t	size_stack(t_stack *stack);
t_stack	*parce_in(int ac, char **av);
void	add_num(t_stack **stack, char *value);

void	free_stack(t_stack *stack);

void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
