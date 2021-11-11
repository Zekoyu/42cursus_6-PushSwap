/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:16:25 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/09 16:47:49 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	int	i;
	int	first;

	if (stack->height <= 1)
		return ;
	first = stack->values[0];
	i = 0;
	while (i < stack->height - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[i] = first;
}

void	reverse_rotate_a(t_stacks *stacks)
{
	if (stacks->stack_a.height > 1)
	{
		reverse_rotate_stack(&stacks->stack_a);
		ft_putstr("rra\n");
	}
}

void	reverse_rotate_b(t_stacks *stacks)
{
	if (stacks->stack_b.height > 1)
	{
		reverse_rotate_stack(&stacks->stack_b);
		ft_putstr("rrb\n");
	}
}

void	reverse_rotate_both(t_stacks *stacks)
{
	if (stacks->stack_a.height > 1 || stacks->stack_b.height > 1)
	{
		reverse_rotate_stack(&stacks->stack_a);
		reverse_rotate_stack(&stacks->stack_b);
		ft_putstr("rrr\n");
	}
}
