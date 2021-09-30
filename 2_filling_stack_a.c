/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_filling_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:04 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 21:08:55 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!new)
		return ;
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

t_stack	*filling_stack_a(char **array, t_stack **begin_list_a)
{
	t_stack		*list;
	t_stack		*new;
	int			i;
	int			n;

	if (!array || !*array)
		return (NULL);
	list = *begin_list_a;
	i = 1;
	while (array[i])
	{
		n = ft_atoi(array[i]);
		new = get_lst_new_elem(n);
		if (!new)
			error_case("Error\nCan't allocate memory\n");
		lstadd_back(&list, new);
		i++;
	}
	return (*begin_list_a);
}
