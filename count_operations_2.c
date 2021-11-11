/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:48:49 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 19:49:01 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If index is 0, we only need one more move to get it on top, and so on
int	count_using_reverse_rotate_both(t_stacks *stacks, int index_a)
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
	count = max (index_a + 1, index_b + 1);
	return (count);
}

/*
	Here we can use 2 if instead of 1 if with brackets containing 2 lines
	This magic trick saved me the lines needed
*/
int	count_op_to_sort_index_a(t_stacks *stacks, int index)
{
	int				normal;
	int				rotate;
	int				rev_rotate;
	int				res;

	res = 0;
	normal = count_using_normal_rotates(stacks, index);
	rotate = count_using_rotate_both(stacks, index);
	rev_rotate = count_using_reverse_rotate_both(stacks, index);
	if (normal <= rotate && normal <= rev_rotate)
		res = normal;
	else if (rotate <= normal && rotate <= rev_rotate)
		res = rotate;
	else if (rev_rotate <= normal && rev_rotate <= rotate)
		res = rev_rotate;
	return (res);
}

/*
	If our value is bigger than the biggest, then we should put int on top of it
	
	But if our value is smaller than the smallest, we should to the same because
	the smallest should be put right after the biggest, like so :
	biggest - smallest - previous smallest ([Some numbers] - 8 - 1 - 2)
*/
int	find_insertion_index_in_b(t_stacks *stacks, int val)
{
	t_stack	*b;
	int		i;

	b = &stacks->stack_b;
	if (val >= get_biggest_val_in_stack(b))
		return (get_index_of_val(b, get_biggest_val_in_stack(b)));
	else if (val <= get_smolest_val_in_stack(b))
		return (get_index_of_val(b, get_biggest_val_in_stack(b)));
	else if (val >= get_stack_top(b) && val <= get_stack_bottom(b))
		return (get_index_of_val(b, get_stack_top(b)));
	else
	{
		i = 0;
		while (i < b->height - 1)
		{
			if (get_val_of_index(b, i) <= val
				&& val <= get_val_of_index(b, i + 1))
				return (i);
			i++;
		}
	}
	return (-1);
}
