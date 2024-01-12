/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:34 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/12 22:15:33 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

# include "MYLIB/mylib.h"
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

t_stack	*parce_in(int ac, char **av);
void	add_num(t_stack **stack, char *value);

void	sa(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);

#endif
