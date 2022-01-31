/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:16:25 by mframbou          #+#    #+#             */
/*   Updated: 31-01-2022 16:57 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate_stack(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->height <= 1)
		return ;
	last = stack->values[stack->height - 1];
	i = stack->height - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[i] = last;
}

void	rotate_a(t_stacks *stacks)
{
	if (stacks->stack_a.height > 1)
	{
		rotate_stack(&stacks->stack_a);
	}
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->stack_b.height > 1)
	{
		rotate_stack(&stacks->stack_b);
	}
}

void	rotate_both(t_stacks *stacks)
{
	if (stacks->stack_a.height > 1 || stacks->stack_b.height > 1)
	{
		rotate_stack(&stacks->stack_a);
		rotate_stack(&stacks->stack_b);
	}
}
