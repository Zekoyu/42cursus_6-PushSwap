/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:53:10 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 19:55:01 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	get_big_s(t_stack *stack)
{
	return (get_biggest_val_in_stack(stack));
}

static inline int	get_small_s(t_stack *stack)
{
	return (get_smolest_val_in_stack(stack));
}

static inline int	get_val_i(t_stack *stack, int index)
{
	return (get_val_of_index(stack, index));
}

void	sort_15_numbers_or_less(t_stacks *stacks)
{
	t_stack	*a;
	int		b_top;
	int		i;

	a = &stacks->stack_a;
	b_top = get_stack_top(&stacks->stack_b);
	while (stacks->stack_a.height > 3)
		push_b(stacks);
	sort_3_numbers_or_less(stacks);
	while (stacks->stack_b.height > 0)
	{
		i = -1;
		b_top = get_stack_top(&stacks->stack_b);
		if (b_top > get_big_s(a) || b_top < get_small_s(a))
			i = get_index_of_val(a, get_small_s(a));
		else
		{
			while (++i < a->height - 1)
				if (get_val_i(a, i) >= b_top && b_top >= get_val_i(a, i + 1))
					break ;
		}
		push_index_to_top_a(stacks, i);
		push_a(stacks);
	}
	push_index_to_top_a(stacks, get_index_of_val(a, get_small_s(a)));
}
