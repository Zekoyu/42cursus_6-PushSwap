/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:26:52 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/09 15:24:50 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_top(t_stack *stack)
{
	if (stack->height < 1)
		return (0);
	return (stack->values[stack->height - 1]);
}

int	get_stack_bottom(t_stack *stack)
{
	if (stack->height < 1)
		return (0);
	return (stack->values[0]);
}

int	get_index_of_val(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (i < stack->height)
	{
		if (stack->values[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

int	get_val_of_index(t_stack *stack, int index)
{
	if (index < 0 || index >= stack->height)
		return (-1);
	return (stack->values[index]);
}
