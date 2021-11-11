/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:54:14 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 19:54:24 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2_numbers(t_stacks *stacks)
{
	int	top;
	int	bot;

	if (stacks->stack_a.height == 1)
		return ;
	top = stacks->stack_a.values[1];
	bot = stacks->stack_a.values[0];
	if (top > bot)
		swap_a(stacks);
}

void	sort_3_numbers_or_less(t_stacks *stacks)
{
	int	bot;
	int	mid;
	int	top;

	if (stacks->stack_a.height == 2)
		return (sort_2_numbers(stacks));
	bot = stacks->stack_a.values[0];
	mid = stacks->stack_a.values[1];
	top = stacks->stack_a.values[2];
	if (bot > mid && bot > top && mid < top)
		swap_a(stacks);
	else if (bot < mid && mid < top && top > mid)
	{
		rotate_a(stacks);
		swap_a(stacks);
	}
	else if (mid < top && mid < bot && bot < top)
		rotate_a(stacks);
	else if (mid > top && mid > bot && bot > top)
	{
		swap_a(stacks);
		rotate_a(stacks);
	}
	else if (mid > top && mid > bot && bot < top)
		reverse_rotate_a(stacks);
}
