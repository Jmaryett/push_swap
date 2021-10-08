/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parsing_and_filling_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:55:35 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/08 17:27:50 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//создаем массив для аргументов, кторые возвращаются из сплита
//проверяем их на содержание только чисел и минуса в начале(validate arguments)
//затем превращаем в число, проверяем на мин и макс, и помещаем в стек
//если при валидации или перемещении возникла 
//ошибка - чистим массив и возвр ошибку

static void	parse_and_validate_argument(t_stack **data_stack, char *argument)
{
	char	**splited_argumets;

	splited_argumets = ft_split(argument, ' ');
	if (!(validate_arguments(splited_argumets))
		|| !(add_arguments_to_stack(data_stack, splited_argumets)))
	{
		free_array_of_strings(splited_argumets);
		error_case_for_push("Error\n");
	}
	free_array_of_strings(splited_argumets);
	return ;
}

static t_stack	*fill_with_numbers(int number_arguments, char **argument)
{
	t_stack	*data_stack;
	int		i;

	i = -1;
	data_stack = NULL;
	while (++i < number_arguments)
		parse_and_validate_argument(&data_stack, argument[i]);
	return (data_stack);
}

//проверяем, отсортирован ли стек и есть в нем дупликаты
//1 это отсортирован, 0-нет; по умолчанию задаем значение 1

static int	check_duplicats_and_is_sorted(t_stack *data_stack,
										int is_array_sorted)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = data_stack;
	while (tmp)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (tmp->number == tmp_next->number)
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			if (tmp->number >= tmp_next->number)
				is_array_sorted = 0;
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	if (is_array_sorted == 1)
		return (-1);
	return (0);
}

//проверяем размер стека и дупликаты

static int	validate_stack(t_stack *data_stack)
{
	int	is_array_sorted;

	is_array_sorted = 1;
	if (lstsize(data_stack) < 2)
		exit(1);
	is_array_sorted = check_duplicats_and_is_sorted(data_stack,
			is_array_sorted);
	if (is_array_sorted == -1)
		exit (1);
	return (1);
}

//в ф-ю заполнения стека подаем сразу без арг без имени проги и,
//соответственно, с меньшим количеством ас

t_stack	*parse_and_validate_input(int ac, char **av)
{
	t_stack	*data_stack;

	if (ac < 2)
		return (NULL);
	data_stack = fill_with_numbers(--ac, ++av);
	validate_stack(data_stack);
	return (data_stack);
}
