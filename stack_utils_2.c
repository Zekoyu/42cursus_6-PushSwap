/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:52:22 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 20:07:51 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_val_in_stack(t_stack *stack)
{
	int	i;
	int	max;

	if (stack->height < 1)
		return (-1);
	i = 0;
	max = stack->values[i++];
	while (i < stack->height)
	{
		if (stack->values[i] > max)
			max = stack->values[i];
		i++;
	}
	return (max);
}

int	get_smolest_val_in_stack(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->values[i++];
	while (i < stack->height)
	{
		if (stack->values[i] < min)
			min = stack->values[i];
		i++;
	}
	return (min);
}

void	push_index_to_top_a(t_stacks *stacks, int index)
{
	int		mid;
	int		val;
	t_stack	*a;

	a = &stacks->stack_a;
	if (index >= a->height || index < 0)
		return ;
	val = a->values[index];
	mid = (a->height - 1) / 2;
	if (index < mid)
		while (get_stack_top(a) != val)
			reverse_rotate_a(stacks);
	else
		while (get_stack_top(a) != val)
			rotate_a(stacks);
}

void	push_index_to_top_b(t_stacks *stacks, int index)
{
	int		mid;
	int		val;
	t_stack	*b;

	b = &stacks->stack_b;
	if (index >= b->height || index < 0)
		return ;
	val = b->values[index];
	mid = (b->height - 1) / 2;
	if (index < mid)
		while (get_stack_top(b) != val)
			reverse_rotate_b(stacks);
	else
		while (get_stack_top(b) != val)
			rotate_b(stacks);
}
