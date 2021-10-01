/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:51 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/01 23:44:23 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	even_init_mv_in_b(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	if (len == 2)
	{
		tmp->moves = 1;
		tmp->next->moves = 2;
		return ;
	}
	while (i <= len / 2)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i++;
	}
	while (i >= 2 && tmp)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i--;
	}
}

void	even_init_mv_in_a(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = (*st)->next;
	while (i < len / 2)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i++;
	}
	while (i >= 1 && tmp)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i--;
	}
}

int	init_first_best_elem(t_best *best, t_stack **b, t_stack **a)
{
	best->tmp_b = *b;
	best->tmp_a = needed_elem_in_a(a, &best->tmp_b);
	if (!best->tmp_a)
		return (0);
	best->min = best->tmp_b->moves + best->tmp_a->moves;
	best->elem_mv = best->tmp_b;
	best->tmp_b = best->tmp_b->next;
	return (1);
}
