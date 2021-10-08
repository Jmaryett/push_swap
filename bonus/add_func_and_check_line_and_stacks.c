/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func_and_check_line_and_stacks.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:18:49 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/08 17:26:46 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_stacks(t_stack **a, t_stack **b)
{
	if (!b || !*b)
	{
		if (is_sorted(*a) == 0)
			write_msg_free_memory_and_exit("OK\n", *a, 0);
		else
			write_msg_free_memory_and_exit("KO\n", *a, 1);
	}
	else
	{
		free_memory_lst(*b);
		write_msg_free_memory_and_exit("KO\n", *a, 1);
	}
}

void	add_check_commands(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp("rb", line, ft_strlen(line)) == 0)
		rotate (b);
	else if (ft_strncmp("rr", line, ft_strlen(line)) == 0)
	{
		rotate (a);
		rotate (b);
	}
	else if (ft_strncmp("rra", line, ft_strlen(line)) == 0)
		reverse_rotate (a);
	else if (ft_strncmp("rrb", line, ft_strlen(line)) == 0)
		reverse_rotate (b);
	else if (ft_strncmp("rrr", line, ft_strlen(line)) == 0)
	{
		reverse_rotate (a);
		reverse_rotate (b);
	}
	else
		error_case_for_push("Error\n");
}

void	write_msg_free_memory_and_exit(char *msg, t_stack *mem, int exit_code)
{
	free_memory_lst(mem);
	ft_putstr_fd(msg, 1);
	exit (exit_code);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	while (tmp)
	{
		if (stack->number >= tmp->number)
			return (-1);
		stack = stack->next;
		tmp = tmp->next;
	}
	return (0);
}
