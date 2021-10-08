/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:41 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/08 12:08:31 by chudapak         ###   ########.fr       */
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

void	write_msg_free_memory_and_exit(char *msg, t_stack *mem, int exit_code)
{
	free_memory_lst(mem);
	ft_putstr_fd(msg, 1);
	exit (exit_code);
}

// ДОДЕЛАТЬ: норму и потести еще
// Предупреждение - у тебя пуш свап на 4 работает тип а там реально написанно - БОНУСЫ ПРОВЕРЯТЬ ЕСЛИ ВСЕ **ИДЕАЛЬНО** РАБОТАЕТ
// Попроси леху выставить слоты и надейся что попадешь на челов с новой волны)) Если тебя 2 без бонусов поставят, а один с бонусами у тебя всеравно будет 3 лвл)
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
	//не пихай ебаные exit везде пиздец какой-то
	if (is_sorted(stack_a) == 0) 					//проверяем отсортирован ли список и если да то пишем ОК и выходим
		write_msg_free_memory_and_exit("OK\n", stack_a, 0);
	starting_to_check(&stack_a);
	free_memory_lst(stack_a);
	return (0);
}
