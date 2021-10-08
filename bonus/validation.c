#include "push_swap_bonus.h"

//создаем массив для аргументов, кторые возвращаются из сплита
//проверяем их на содержание только чисел и минуса в начале(validate arguments)
//затем превращаем в число, проверяем на мин и макс, и помещаем в стек
//если при валидации или перемещении возникла 
//ошибка - чистим массив и возвр ошибку

static void	parse_and_validate_argument(t_stack **stack_a, char *argument)
{
	char	**splited_argumets;

	splited_argumets = ft_split(argument, ' ');
	if (!(validate_arguments(splited_argumets))
		|| !(add_arguments_to_stack(stack_a, splited_argumets)))
	{
		free_array_of_strings(splited_argumets);
		error_case_for_push("Error\n");
	}
	free_array_of_strings(splited_argumets);
	return ;
}

static t_stack	*fill_with_numbers(int number_arguments, char **argument)
{
	t_stack	*stack_a;
	int		i;

	i = -1;
	stack_a = NULL;
	while (++i < number_arguments)
		parse_and_validate_argument(&stack_a, argument[i]);
	return (stack_a);
}

//проверяем, есть ли дубликаты

static int	check_duplicats(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = stack_a;
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
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

//проверяем размер стека и дубликаты

static int	validate_stack(t_stack *stack_a)
{
	int	has_duplicat;

	has_duplicat = 1;
	if (lstsize(stack_a) < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	has_duplicat = check_duplicats(stack_a);
	if (has_duplicat == -1)
		exit (1);
	return (1);
}

//в ф-ю заполнения стека подаем сразу без арг, без имени проги и,
//соответственно, с меньшим количеством ас

t_stack	*parse_validate_input(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2)
		return (NULL);
	stack_a = fill_with_numbers(--ac, ++av);
	validate_stack(stack_a);
	return (stack_a);
}