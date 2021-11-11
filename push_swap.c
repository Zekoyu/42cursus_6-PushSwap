/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:51 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/11 12:26:43 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	release_stack_hostages(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->stack_a;
	b = &stacks->stack_b;
	free(a->values);
	free(b->values);
}

/*
	‣ Find the value which require the least amount to be pushed to B
	‣ Push it in the right place in B.
	‣ Repeat until A is empty
	‣ Then put the biggest one on top of B
	‣ Just push all of B in A
	‣ Magic is done
*/
int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1 || !init_both_stacks(&stacks, argc, argv))
		return (EXIT_FAILURE);
	if (array_is_sorted(stacks.stack_a.values, stacks.stack_a.capacity))
	{
		release_stack_hostages(&stacks);
		return (EXIT_SUCCESS);
	}
	if (stacks.stack_a.height <= 3)
		sort_3_numbers_or_less(&stacks);
	else if (stacks.stack_a.height <= 15)
		sort_15_numbers_or_less(&stacks);
	else
	{
		while (stacks.stack_a.height > 0)
			push_lowest_op_index_a(&stacks);
		push_index_to_top_b(&stacks, get_index_of_val(&stacks.stack_b,
				get_biggest_val_in_stack(&stacks.stack_b)));
		while (stacks.stack_b.height > 0)
			push_a(&stacks);
	}
	release_stack_hostages(&stacks);
	return (EXIT_SUCCESS);
}
