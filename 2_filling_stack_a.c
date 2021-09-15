#include "push_swap.h"

//creating element of the list with content
static void	lstadd_back(t_stack_a **begin_list_a, t_stack_a *new)
{
	t_stack_a	*tmp;

	if (!begin_list_a)
		return ;
	if (!*begin_list_a)
		*begin_list_a = new;
	else
	{
		tmp = *begin_list_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//if memory can't allocate we free the list
void	free_memory_lst(t_stack_a *new)
{
	t_stack_a	*tmp;

	while (new)
	{
		tmp = new->next;
		free(new);
		new = tmp;
	}
}

//adding content to the new elem of list
static t_stack_a	*get_lst_new_elem(int n)
{
	t_stack_a	*new;

	new = malloc(sizeof(t_stack_a));
	if (!new)
		return (NULL);
	new->number = n;
	new->next = NULL;
	return (new);
}

//creating first elem of the list with the content

void	filling_stack_a(char **array, t_stack_a **begin_list_a)
{
	//will be saved as the pointer to the first elem of list
	t_stack_a	*new;
	int			i;
	int			n;

	i = 1;
	while (array[i])
	{
		n = ft_atoi(array[i]);
		new = get_lst_new_elem(n);
		if (!new)
			error_case("Error\nCan't allocate memory\n");
		lstadd_back(begin_list_a, new);
		i++;
	}
}