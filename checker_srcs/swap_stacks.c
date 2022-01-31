/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:30 by mframbou          #+#    #+#             */
/*   Updated: 31-01-2022 16:57 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_stack(t_stack *stack)
{
	int		top;
	int		belowtop;

	if (stack->height < 2)
		return ;
	top = stack->values[stack->height - 1];
	belowtop = stack->values[stack->height - 2];
	stack->values[stack->height - 1] = belowtop;
	stack->values[stack->height - 2] = top;
}

void	swap_a(t_stacks	*stacks)
{
	if (stacks->stack_a.height >= 2)
	{
		swap_stack(&stacks->stack_a);
	}
}

void	swap_b(t_stacks	*stacks)
{
	if (stacks->stack_a.height >= 2)
	{
		swap_stack(&stacks->stack_a);
	}
}

void	swap_both(t_stacks	*stacks)
{
	if (stacks->stack_a.height >= 2 || stacks->stack_b.height >= 2)
	{
		swap_stack(&stacks->stack_a);
		swap_stack(&stacks->stack_b);
	}
}
