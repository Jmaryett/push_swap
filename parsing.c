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
	while (tmp) {
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n"); */
	return (data_stack);
}

t_stack	*parse_and_validate_input(int ac, char **av)
{
	t_stack	*data_stack;

	if (ac < 2)
		exit(1);
	data_stack = fill_with_numbers(--ac, ++av);
	return (data_stack);
}