/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_one_elt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:40:20 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 15:58:07 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lowest_op_using_normal(t_stacks *stacks, int index_a)
{
	int	index_b;
	int	val;

	val = get_val_of_index(&stacks->stack_a, index_a);
	push_index_to_top_a(stacks, index_a);
	if (stacks->stack_b.height > 1)
	{
		index_b = find_insertion_index_in_b(stacks, val);
		push_index_to_top_b(stacks, index_b);
	}
	push_b(stacks);
}

/*
	Reverse rotate until one of our values reach the top
	Then just rotate the stacks (if needed) to get the value of
	the other stack on top
*/
static void	push_lowest_op_using_reverse(t_stacks *stacks, int index_a)
{
	int	val_a;
	int	val_b;

	val_a = get_val_of_index(&stacks->stack_a, index_a);
	val_b = 0;
	if (stacks->stack_b.height > 1)
		val_b = get_val_of_index(&stacks->stack_b,
				find_insertion_index_in_b(stacks, val_a));
	while (!(get_stack_top(&stacks->stack_a) == val_a
			|| get_stack_top(&stacks->stack_b) == val_b))
	{
		reverse_rotate_both(stacks);
	}
	push_index_to_top_a(stacks, get_index_of_val(&stacks->stack_a, val_a));
	push_index_to_top_b(stacks, get_index_of_val(&stacks->stack_b, val_b));
	push_b(stacks);
}

static void	push_lowest_op_using_rotate(t_stacks *stacks, int index_a)
{
	int	val_a;
	int	val_b;

	val_a = get_val_of_index(&stacks->stack_a, index_a);
	val_b = 0;
	if (stacks->stack_b.height > 1)
		val_b = get_val_of_index(&stacks->stack_b,
				find_insertion_index_in_b(stacks, val_a));
	while (!(get_stack_top(&stacks->stack_a) == val_a
			|| get_stack_top(&stacks->stack_b) == val_b))
	{
		rotate_both(stacks);
	}
	push_index_to_top_a(stacks, get_index_of_val(&stacks->stack_a, val_a));
	push_index_to_top_b(stacks, get_index_of_val(&stacks->stack_b, val_b));
	push_b(stacks);
}

/*
	Damned double if caused my code to fail, fuck the norme
*/
void	push_lowest_op_index_a(t_stacks *stacks)
{
	int				i;
	int				min;
	int				tmp;
	int				res_index;

	if (stacks->stack_a.height < 1)
		return ;
	min = count_op_to_sort_index_a(stacks, 0);
	res_index = 0;
	i = 0;
	while (++i < stacks->stack_a.height)
	{
		tmp = count_op_to_sort_index_a(stacks, i);
		if (tmp < min)
		{
			res_index = i;
			min = tmp;
		}
	}
	if (min == count_using_normal_rotates(stacks, res_index))
		push_lowest_op_using_normal(stacks, res_index);
	else if (min == count_using_rotate_both(stacks, res_index))
		push_lowest_op_using_rotate(stacks, res_index);
	else if (min == count_using_reverse_rotate_both(stacks, res_index))
		push_lowest_op_using_reverse(stacks, res_index);
}
