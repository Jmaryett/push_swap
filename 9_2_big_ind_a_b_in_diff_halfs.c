/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_2_big_ind_a_b_in_diff_halfs.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:54:14 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 21:18:15 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_up_b_down(t_stack **a, t_stack **b, t_best *best)
{
	t_stack	*first_should_be;

	first_should_be = best->tmp_a->next;
	if (best->tmp_a->moves == 0)
	{
		push_b_down(b);
		return ;
	}
	while (*a != first_should_be)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push_b_down(b);
	return ;
}

void	a_to_down_b_up(t_stack **a, t_stack **b, t_best *best)
{
	t_stack	*first_should_be;

	first_should_be = best->tmp_a->next;
	if (best->tmp_a->moves == 0)
	{
		push_b_up(b);
		return ;
	}
	while (*a != first_should_be)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	push_b_up(b);
	return ;
}
