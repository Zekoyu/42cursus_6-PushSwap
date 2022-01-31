/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:53:38 by mframbou          #+#    #+#             */
/*   Updated: 31-01-2022 17:22 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*values;
	int		height;
	int		capacity;
}	t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_stacks;

typedef struct s_op_count_plus_type
{
	int	op_count;
	int	type;
}	t_op_count_type;

enum	e_op_type
{
	ROTATE,
	REVERSE,
	NORMAL
};

// Swap
void	swap_a(t_stacks	*stacks);
void	swap_b(t_stacks	*stacks);
void	swap_both(t_stacks	*stacks);

// Push
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);

// Rotate
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_both(t_stacks *stacks);

// Reverse rotate
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_both(t_stacks *stacks);

// Stack utils
int		get_stack_top(t_stack *stack);
int		get_stack_bottom(t_stack *stack);
int		get_index_of_val(t_stack	*stack, int val);
int		get_val_of_index(t_stack *stack, int index);
int		get_biggest_val_in_stack(t_stack *stack);
int		get_smolest_val_in_stack(t_stack *stack);
void	push_index_to_top_a(t_stacks *stacks, int index);
void	push_index_to_top_b(t_stacks *stacks, int index);
int		find_insertion_index_in_b(t_stacks *stacks, int val);

// Counting
int		count_op_to_sort_index_a(t_stacks *stacks, int val);
int		count_using_normal_rotates(t_stacks *stacks, int index_a);
int		count_using_reverse_rotate_both(t_stacks *stacks, int index_a);
int		count_using_rotate_both(t_stacks *stacks, int index_a);

// Actual algorithm
void	push_lowest_op_index_a(t_stacks *stacks);
void	sort_15_numbers_or_less(t_stacks *stacks);
void	sort_3_numbers_or_less(t_stacks *stacks);

// FT Utils
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
long	ft_atol(char *str);
int		max(int a, int b);

// Parsing
int		init_both_stacks(t_stacks *stacks, int argc, char *argv[]);
int		array_has_duplicates(int *array, int array_size);
int		array_is_sorted(int *array, int array_size);
int		is_really_num(char *str);

void	release_stack_hostages(t_stacks *stacks);

#endif
