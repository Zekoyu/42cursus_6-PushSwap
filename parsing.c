/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:14:28 by mframbou          #+#    #+#             */
/*   Updated: 31-01-2022 17:22 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*parse_list_of_args(char *str_nums[], int argc)
{
	int		i;
	int		j;
	long	val;
	int		*res;

	i = argc - 1;
	j = 0;
	res = (int *) malloc(sizeof(int) * argc);
	if (res)
	{
		while (i >= 0)
		{
			val = ft_atol(str_nums[i]);
			if (!is_really_num(str_nums[i]) || val == 999999999999L)
			{
				free(res);
				return (NULL);
			}
			res[j++] = ft_atol(str_nums[i--]);
		}
	}
	return (res);
}

static int	*parse_string_of_args(char *str, int *argc)
{
	char	**numbers;
	int		count;

	numbers = ft_split(str, ' ');
	if (!numbers)
		return (NULL);
	count = 0;
	while (numbers[count])
		count++;
	*argc = count;
	return (parse_list_of_args(numbers, count));
}

static int	*parse_values(int *argc, char *argv[])
{
	int	*values;

	if (*argc < 1)
		values = NULL;
	else if (*argc == 1)
		values = parse_string_of_args(argv[0], argc);
	else
		values = parse_list_of_args(argv, *argc);
	return (values);
}

static int	*init_empty_array(int size)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * size);
	if (!res || size <= 0)
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = 0;
	return (res);
}

int	init_both_stacks(t_stacks *stacks, int argc, char *argv[])
{
	int	*values_a;
	int	*values_b;

	argc--;
	argv++;
	values_a = parse_values(&argc, argv);
	values_b = init_empty_array(argc);
	if (!values_a || !values_b || array_has_duplicates(values_a, argc))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free(values_a);
		free(values_b);
		return (0);
	}
	stacks->stack_a.capacity = argc;
	stacks->stack_a.height = argc;
	stacks->stack_a.values = values_a;
	stacks->stack_b.capacity = argc;
	stacks->stack_b.height = 0;
	stacks->stack_b.values = values_b;
	return (1);
}
