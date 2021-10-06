/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_only_big_ind_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:19:36 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 21:19:47 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//here i find suitable index from a to left big index in b

static int	cycle_for_smaller_ind(t_stack **a, t_stack **b, t_stack **needed)
{
	int		count;
	t_stack	*tmp_a;

	count = 0;
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > (*b)->index)
			tmp_a = tmp_a->next;
		else if ((*b)->index - tmp_a->index < 0
			|| (*b)->index - (*needed)->index < 0)
			*needed = tmp_a->next;
		else if ((*b)->index - tmp_a->index < (*b)->index - (*needed)->index
			|| (*b)->index - tmp_a->index == (*b)->index - (*needed)->index)
		{
			*needed = tmp_a;
			tmp_a = tmp_a->next;
			count = 1;
		}
		else
			tmp_a = tmp_a->next;
	}
	return (count);
}

t_stack	*smaller_index_for_b(t_stack **a, t_stack **b)
{
	t_stack	*needed;
	int		count;

	if (!a || !*a || !b)
		return (NULL);
	count = 0;
	needed = *a;
	count = cycle_for_smaller_ind(a, b, &needed);
	if (count == 0)
		return (NULL);
	return (needed);
}

//here i find best bigger index left in b

int	best_bigger_index_to_move(t_stack **a, t_stack **b, t_best *best)
{
	if (!init_first_best_bigger_ind_to_move(best, b, a))
		return (0);
	while (best->tmp_b)
	{
		best->tmp_a = smaller_index_for_b(a, &best->tmp_b);
		if (best->tmp_b->moves + best->tmp_a->moves < best->min)
		{
			best->min = best->tmp_a->moves + best->tmp_b->moves;
			best->elem_mv = best->tmp_b;
		}
		else if (best->tmp_b->moves + best->tmp_a->moves == best->min)
		{
			if (best->tmp_b->index < best->elem_mv->index)
				best->elem_mv = best->tmp_b;
			best->tmp_b = best->tmp_b->next;
		}
		else
			best->tmp_b = best->tmp_b->next;
	}
	best->elem_mv->best_to_move_to_a = 1;
	best->tmp_a = smaller_index_for_b(a, &best->elem_mv);
	return (1);
}

void	only_big_index_left(t_stack **a, t_stack **b, t_best *best)
{
	if (!a || !b)
		return ;
	while (*b)
	{
		reinit_mv_in_a(a);
		init_mv_in_b(b);
		if (!best_bigger_index_to_move(a, b, best))
			return ;
		rotating_b_and_a_with_big_ind(b, a, best);
		init_moves(a, b);
	}
}
