/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_indexation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:25 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:47:26 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_index(t_stack **begin)
{
	t_stack	*tmp;

	tmp = *begin;
	while (tmp)
	{
		tmp->index = -2;
		tmp = tmp->next;
	}
}

static void	giving_index(t_stack **begin, int len)
{
	int		i;
	int		min;
	t_stack	*begin_tmp;
	t_stack	*tmp;

	min = INT_MAX;
	i = 0;
	init_index(begin);
	while (i < len)
	{
		begin_tmp = *begin;
		while (begin_tmp)
		{
			if (begin_tmp->number <= min && begin_tmp->index == -2)
			{
				min = begin_tmp->number;
				tmp = begin_tmp;
			}
			begin_tmp = begin_tmp->next;
		}
		min = INT_MAX;
		tmp->index = i;
		i++;
	}
}

void	indexation(t_stack **begin)
{
	int	len;

	if (!begin || !*begin)
		return ;
	len = lstsize(*begin);
	giving_index(begin, len);
}
