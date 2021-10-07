/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:41 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/07 18:50:27 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_line(char **line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp("sa", *line, ft_strlen("sa")))
		swap(a);
	else if (!ft_strncmp("sb", *line, ft_strlen("sb")))
		swap (b);
	else if (!ft_strncmp("ss", *line, ft_strlen("ss")))
	{
		swap (a);
		swap (b);
	}
	else if (!ft_strncmp("pa", *line, ft_strlen("pa")))
		push(b, a);
	else if (!ft_strncmp("pb", *line, ft_strlen("pb")))
		push(a, b);
	else if (!ft_strncmp("ra", *line, ft_strlen("ra")))
		rotate (a);
	else
		add_check_commands(line, a, b);
}

static void	reading_commands(t_stack **a, t_stack **b)
{
	int		i;
	char	*line;

	i = 2;
	while (i != 0 || i != -1)
	{
		i = get_next_line(0, &line);
		check_line(&line, a, b);
		free (line);
	}
	check_stacks(a, b);
}

static void	starting_to_check(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_count	count;

	if (!stack_a || !*stack_a)
		return ;
	stack_b = NULL;
	count.count_false = 0;
	indexation(stack_a);
	reading_commands(stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = parse_and_validate_input(argc, argv);
	if (!stack_a)
		exit(1);
	starting_to_check(&stack_a);
	free_memory_lst(stack_a);
	exit (1);
}
