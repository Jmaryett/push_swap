/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_2_add_func_for_small_ind.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:51 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 21:18:42 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_is_min_ind(t_stack **a, int min)
{
	int		len;
	t_stack	*tmp_a;

	tmp_a = *a;
	len = lstsize(*a) / 2;
	while (len >= 0)
	{
		if (tmp_a->index == min)
			return (1);
		tmp_a = tmp_a->next;
		len--;
	}
	return (0);
}

void	init_moves(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_a->moves = 0;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->moves = 0;
		tmp_b->best_to_move_to_a = 0;
		tmp_b = tmp_b->next;
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

void	push_b_to_a(t_stack **a, t_stack **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}
