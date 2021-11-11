/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:58:06 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 19:55:36 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_push_value_to_top_a(t_stacks *stacks, int val)
{
	int		mid;
	int		count;
	int		index;
	t_stack	*a;

	a = &stacks->stack_a;
	index = get_index_of_val(a, val);
	val = a->values[index];
	mid = (a->height - 1) / 2;
	count = 0;
	if (index < mid)
	{
		while (index != a->height - 1)
		{
			index--;
			if (index < 0)
				index = a->height - 1;
			count++;
		}
	}
	else
		while ((index + count) != a->height - 1)
			count++;
	return (count);
}

static int	count_rotate_value_top_b(t_stacks *stacks, int val)
{
	int		mid;
	int		count;
	int		index;
	t_stack	*b;

	b = &stacks->stack_b;
	index = find_insertion_index_in_b(stacks, val);
	val = b->values[index];
	mid = (b->height - 1) / 2;
	count = 0;
	if (index < mid)
	{
		while (index != b->height - 1)
		{
			index--;
			if (index < 0)
				index = b->height - 1;
			count++;
		}
	}
	else
		while ((index + count) != b->height - 1)
			count++;
	return (count);
}

int	count_using_normal_rotates(t_stacks *stacks, int index_a)
{
	int	count;
	int	val;

	count = 0;
	val = get_val_of_index(&stacks->stack_a, index_a);
	count += count_push_value_to_top_a(stacks, val);
	count += count_rotate_value_top_b(stacks, val);
	return (count);
}

int	count_using_rotate_both(t_stacks *stacks, int index_a)
{
	int	count;
	int	val;
	int	index_b;
	int	height_a_index;
	int	height_b_index;

	count = 0;
	height_a_index = stacks->stack_a.height - 1;
	height_b_index = stacks->stack_b.height - 1;
	val = get_val_of_index(&stacks->stack_a, index_a);
	index_b = find_insertion_index_in_b(stacks, val);
	count = max (height_a_index - index_a, height_b_index - index_b);
	return (count);
}
