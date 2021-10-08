/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_and_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:18:49 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/08 12:04:43 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* static void	check_if_a_is_sorted(t_stack **a)
{
	while (*a)								//у тебя сега из-за этого условия была
	{										//можешь удалить эту функцию
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
} */

void	check_stacks(t_stack **a, t_stack **b)
{
	if (!b || !*b)
	{
		//check_if_a_is_sorted(a); - я написал функцию is_sorted теперь проверяй ей
		//также отдельная функция write_msg_free_memory_and_exit для выхода из программы и вывода сообщения, чтобы код не дублировать
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
		error_case_for_push("Error\nWrong instruction.\n");
}
