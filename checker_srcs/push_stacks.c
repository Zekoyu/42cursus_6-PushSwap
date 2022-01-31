/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:45 by mframbou          #+#    #+#             */
/*   Updated: 31-01-2022 16:57 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push_stack(t_stack *input, t_stack *output)
{
	int	top_i;

	if (input->height < 1)
		return ;
	top_i = input->values[input->height - 1];
	output->values[output->height] = top_i;
	input->values[input->height - 1] = 0;
	input->height--;
	output->height++;
}

void	push_a(t_stacks *stacks)
{
	if (stacks->stack_b.height >= 1)
	{
		push_stack(&stacks->stack_b, &stacks->stack_a);
	}
}

void	push_b(t_stacks *stacks)
{
	if (stacks->stack_a.height >= 1)
	{
		push_stack(&stacks->stack_a, &stacks->stack_b);
	}
}
