/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 17:24 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
	Returns -1 on error,
	0 on success

	Compare with \n since gnl includes it
*/
int	execute_instruction(char *instruction, t_stacks *stacks)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		swap_a(stacks);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		swap_b(stacks);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		swap_both(stacks);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		push_a(stacks);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		push_b(stacks);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		rotate_a(stacks);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rotate_b(stacks);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rotate_both(stacks);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		reverse_rotate_a(stacks);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		reverse_rotate_b(stacks);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		reverse_rotate_both(stacks);
	else
		return (-1);
	return (0);
}

/*
	Returns -1 on error
	0 on success
*/
int	read_and_execute_instructions(t_stacks *stacks)
{
	char	*instruction;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		if (execute_instruction(instruction, stacks) == -1)
		{
			ft_putstr_fd("Eror\n", 1);
			release_stack_hostages(stacks);
			free(instruction);
			return (-1);
		}
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	if (!init_both_stacks(&stacks, argc, argv))
		return (EXIT_FAILURE);
	if (read_and_execute_instructions(&stacks) == -1)
		return (EXIT_FAILURE);
	if (stacks.stack_b.height == 0 \
	&& array_is_sorted(stacks.stack_a.values, stacks.stack_a.capacity))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (EXIT_SUCCESS);
}
