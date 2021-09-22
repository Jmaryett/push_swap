#include "push_swap.h"

//creating element of the list with content
void	lstadd_back(t_stack **begin_list_a, t_stack *new)
{
	t_stack	*tmp;

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
void	free_memory_lst(t_stack *new)
{
	t_stack	*tmp;

	while (new)
	{
		tmp = new->next;
		free(new);
		new = tmp;
	}
}

//adding content to the new elem of list
static t_stack	*get_lst_new_elem(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = n;
	new->next = NULL;
	return (new);
}

//creating first elem of the list with the content

void	filling_stack_a(char **array, t_stack **begin_list_a)
{
	//will be saved as the pointer to the first elem of list
	t_stack	*new;
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