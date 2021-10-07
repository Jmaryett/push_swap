/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_func_to_fill_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:04 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/07 19:38:58 by jmaryett         ###   ########.fr       */
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

//добавляем число в новый элемент списка

t_stack	*get_lst_new_elem(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = n;
	new->next = NULL;
	return (new);
}

int	lstsize(t_stack *begin)
{
	int		len;
	t_stack	*tmp;

	if (!begin)
		return (0);
	tmp = begin;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
