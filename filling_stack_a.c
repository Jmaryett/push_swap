#include "push_swap.h"

int parse_arg(char *arr)
{
	int n;

	n = ft_atoi(arr);

	return (n);
}

t_stack_a *create_new_elem(int n)
{
}

void filling_stack_a(char **array)
{
	t_stack_a *first_list;
	t_stack_a *add_lists;
	int i;
	int n;

	//NEW_LIST = create_new_elem();
	//save first elem pointer
	i = 1;
	while (array[i])
	{
		n = parse_arg(&array[i]);
		create_new_elem(n);
		i++;
	}
}