/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:41 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/07 23:30:43 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_commands(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp("sa", line, ft_strlen("sa")) == 0)
		swap (a);
	else if (ft_strncmp("sb", line, ft_strlen("sb")) == 0)
		swap (b);
	else if (ft_strncmp("ss", line, ft_strlen("ss")) == 0)
	{
		swap (a);
		swap (b);
	}
	else if (ft_strncmp("pa", line, ft_strlen("pa")) == 0)
		push(b, a);
	else if (ft_strncmp("pb", line, ft_strlen("pb")) == 0)
		push(a, b);
	else if (ft_strncmp("ra", line, ft_strlen("ra")) == 0)
		rotate (a);
	else
		add_check_commands(line, a, b);
}

static void	check_line(char *line, t_stack **a, t_stack **b)
{
	if (ft_strlen(line) > 3 || ft_strlen(line) == 1)
		error_case_for_push("Error\nWrong instruction.\n");
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
	while (tmp_a)
	{
		printf("number is = %d, index = %d\n", tmp_a->number, tmp_a->index);
		tmp_a = tmp_a->next;
	}
	reading_commands(stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = parse_validate_input(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	//проверь отсортирован ли список (напиши свою функцию) если да то выведи ОК если нет то начинай выполнять starting_to_check
	//и не пихай ебаные exit везде пиздец какой-то
	starting_to_check(&stack_a);
	free_memory_lst(stack_a);
	return (0);
}
