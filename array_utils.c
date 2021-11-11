/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:39:48 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 17:42:33 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_is_sorted(int *array, int array_size)
{
	int	i;

	i = 1;
	while (array[i - 1] > array[i] && i < array_size)
		i++;
	if (i != array_size)
		return (0);
	return (1);
}

int	array_has_duplicates(int *array, int array_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size)
	{
		j = 0;
		while (j < array_size)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
