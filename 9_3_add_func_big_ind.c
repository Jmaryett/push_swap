/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_2_add_func_big_ind.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:04:46 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 21:05:24 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotating_b_and_a_with_big_ind(t_stack **b, t_stack **a, t_best *best)
{
	int		i_a;
	int		j_b;
	int		len_b;
	int		len_a;

	len_b = lstsize(*b) / 2;
	len_a = lstsize(*a) / 2;
	j_b = where_is_b(len_b, b, best);
	i_a = where_is_a(len_a, a, best);
	if (i_a == 0 && j_b == 0)
		do_rrr(a, b, best);
	else if (i_a == 1 && j_b == 0)
		a_to_up_b_down(a, b, best);
	else if (i_a == 0 && j_b == 1)
		a_to_down_b_up(a, b, best);
	else if (i_a == 1 && j_b == 1)
		do_rr(a, b, best);
	push_b_to_a(a, b);
}

//here i just initiate first best elem to move to a for comparing

int	init_first_best_bigger_ind_to_move(t_best *best, t_stack **b, t_stack **a)
{
	best->tmp_b = *b;
	best->tmp_a = smaller_index_for_b(a, &best->tmp_b);
	if (!best->tmp_a)
		return (0);
	best->min = best->tmp_b->moves + best->tmp_a->moves;
	best->elem_mv = best->tmp_b;
	best->tmp_b = best->tmp_b->next;
	return (1);
}
