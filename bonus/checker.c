/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:41 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/08 17:42:06 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_commands(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp("sa", line, ft_strlen(line)) == 0)
		swap (a);
	else if (ft_strncmp("sb", line, ft_strlen(line)) == 0)
		swap (b);
	else if (ft_strncmp("ss", line, ft_strlen(line)) == 0)
	{
		swap (a);
		swap (b);
	}
	else if (ft_strncmp("pa", line, ft_strlen(line)) == 0)
		push(b, a);
	else if (ft_strncmp("pb", line, ft_strlen(line)) == 0)
		push(a, b);
	else if (ft_strncmp("ra", line, ft_strlen(line)) == 0)
		rotate (a);
	else
		add_check_commands(line, a, b);
}

static void	check_line(char *line, t_stack **a, t_stack **b)
{
	if (ft_strlen(line) > 3 || ft_strlen(line) <= 1)
		error_case_for_push("Error\n");
	check_commands(line, a, b);
}

static void	reading_commands(t_stack **a, t_stack **b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		check_line(line, a, b);
		free (line);
	}
	check_stacks(a, b);
}

static void	starting_to_check(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*tmp_a;

	if (!stack_a || !*stack_a)
		return ;
	stack_b = NULL;
	indexation(stack_a);
	tmp_a = *stack_a;
	reading_commands(stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_validate_input(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_sorted(stack_a) == 0)
		write_msg_free_memory_and_exit("OK\n", stack_a, 0);
	starting_to_check(&stack_a);
	free_memory_lst(stack_a);
	exit (1);
}
