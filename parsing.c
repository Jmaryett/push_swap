#include "push_swap.h"

void	free_array_of_strings(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free (t[i]);
		i++;
	}
	free(t);
}

int	is_digitc(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_str_digit(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (!is_digitc(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	validate_arguments(char **arguments)
{
	int		i;

	i = 0;
	while (arguments[i] != NULL)
	{
		if (is_str_digit(arguments[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	add_arguments_to_stack(t_stack **data_stack, char **arguments)
{
	int		i;
	long	number;
	t_stack	*tmp;

	i = 0;
	while (arguments[i] != NULL)
	{
		number = ft_atoi(arguments[i]);
		if (number < INT_MIN || INT_MAX < number)
			return (-1);
		tmp = get_lst_new_elem((int)number);
		if (!tmp)
			return (-1);
		lstadd_back(data_stack, tmp);
		i++;
	}
	return (0);
}

int	parse_and_validate_argument(t_stack **data_stack, char *argument)
{
	char	**splited_argumets;

	splited_argumets = ft_split(argument, ' ');
	/* for (int i = 0; splited_argumets[i] != NULL; i++)
		printf("%s\n", splited_argumets[i]); */
	if (validate_arguments(splited_argumets) == -1
		|| add_arguments_to_stack(data_stack, splited_argumets) == -1)
	{
		free_array_of_strings(splited_argumets);
		return (-1);
	}
	free_array_of_strings(splited_argumets);
	return (0);
}

t_stack	*fill_with_numbers(int number_arguments, char **argument)
{
	t_stack	*data_stack;
	int		i;

	i = -1;
	data_stack = NULL;
	while (++i < number_arguments)
	{
		if (parse_and_validate_argument(&data_stack, argument[i]) == -1)
		{
			free_memory_lst(data_stack);
			return (NULL);
		}
	}
/* 	printf("------------------\n");
	t_stack *tmp;
	tmp = data_stack;
	while (tmp) {															//для тестиков шместиков
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n"); */
	return (data_stack);
}
/*
** Здесь проверяем отсортирован ли массив и есть ли в нем повторяющиеся числа
*/
int	check_duplicants_and_is_sorted(t_stack *data_stack)
{
	t_stack	*i;
	t_stack	*j;
	int		is_array_sorted;				//1 это отсортирован 0 нет, по умолчанию задаем значение 1

	is_array_sorted = 1;
	i = data_stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number == j->number)
				return (-1);
			if (i->number >= j->number)
				is_array_sorted = 0;
			j = j->next;
		}
		i = i->next;
	}
	if (is_array_sorted == 1)
		return (-1);
	return (0);
}

int	validate_stack(t_stack *data_stack)
{
	if (lstsize(data_stack) < 2)
		return (-1);
	if (check_duplicants_and_is_sorted(data_stack))
		return (-1);
	return (0);
}

/*
** Все что закоментил можешь смело удалять
** В кратце - сначала проверяем количество аргументов;
**			- заполняем стак распареными значениями
**				- добавляем каждый аргумент по отдельности предварительно прогнав его через сплит
**				  а потом проверив число это или нет (50-19 - такое говно не проходит)
**				- потом все аргументы которые выдал сплит добавляем в конец к data_stack
**				  (все запротектил, да же если память не выделится, то стоит протект)
**			- валидируем стэк
**				- сначала проверяем размер стэка
**				- потом в одном цикле проверяем есть ли дупликаты и смотрим отсортирован ли уже список.
*/

t_stack	*parse_and_validate_input(int ac, char **av)
{
	t_stack	*data_stack;

	if (ac < 2)
		return (NULL);
	data_stack = fill_with_numbers(--ac, ++av);
	if (validate_stack(data_stack) == -1)
	{
		free_memory_lst(data_stack);
		data_stack = NULL;
	}
	return (data_stack);
}