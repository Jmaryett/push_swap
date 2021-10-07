/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_and_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:18:49 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/07 19:56:36 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_if_a_is_sorted(t_stack **a)
{
	while (*a)
	{
		if ((*a)->index < (*a)->next->index)
			*a = (*a)->next;
		else
		{
			free_memory_lst(*a);
			write (1, "KO\n", 3);
			exit (1);
		}
	}
	write (1, "OK\n", 3);
	exit (1);
}

void	check_stacks(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		check_if_a_is_sorted(a);
	else
	{
		free_memory_lst(*a);
		free_memory_lst(*b);
		write (1, "KO\n", 3);
		exit (1);
	}
}

void	add_check_commands(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp("rb", line, ft_strlen("sb")) == 0)
		rotate (b);
	else if (ft_strncmp("rr", line, ft_strlen("rr")) == 0)
	{
		rotate (a);
		rotate (b);
	}
	else if (ft_strncmp("rra", line, ft_strlen("rra") == 0))
		reverse_rotate (a);
	else if (ft_strncmp("rrb", line, ft_strlen("rrb") == 0))
		reverse_rotate (b);
	else if (ft_strncmp("rrr", line, ft_strlen("rrr") == 0))
	{
		reverse_rotate (a);
		reverse_rotate (b);
	}
	else if (ft_strlen(line) > 3)
		error_case_for_push("Error\nWrong instruction.\n");
	else
	{
		free_memory_lst (*a);
		free_memory_lst (*b);
		error_case_for_push("Error\nWrong instruction.\n");
	}
}
