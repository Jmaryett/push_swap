/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_1_big_ind_rr_rrr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:54:14 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 21:14:54 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_do_rr_big(t_stack **a, t_stack **b, t_best **best)
{
	t_stack	*first_should_be;

	first_should_be = (*best)->tmp_a->next;
	while (*a != first_should_be && *b != (*best)->elem_mv)
	{
		rotate(a);
		rotate(b);
		write (1, "rr\n", 3);
	}
	if (*a != first_should_be)
	{
		while (*a != first_should_be)
		{
			rotate(a);
			write (1, "ra\n", 3);
		}
	}
	else if (*b != (*best)->elem_mv)
	{
		while (*b != (*best)->elem_mv)
		{
			rotate(b);
			write (1, "rb\n", 3);
		}
	}
}

void	do_rr(t_stack **a, t_stack **b, t_best *best)
{
	if (best->tmp_a->moves == 0)
		push_b_up(b);
	else
		add_do_rr_big(a, b, &best);
	return ;
}

static void	add_do_rrr_big(t_stack **a, t_stack **b, t_best **best)
{
	t_stack	*first_should_be;

	first_should_be = (*best)->tmp_a->next;
	while (*a != first_should_be && *b != (*best)->elem_mv)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write (1, "rrr\n", 4);
	}
	if (*a != first_should_be)
	{
		while (*a != first_should_be)
		{
			reverse_rotate(a);
			write (1, "rra\n", 4);
		}
	}
	else if (*b != (*best)->elem_mv)
	{
		while (*b != (*best)->elem_mv)
		{
			reverse_rotate(b);
			write (1, "rrb\n", 4);
		}
	}
}

void	do_rrr(t_stack **a, t_stack **b, t_best *best)
{
	if (best->tmp_a->moves == 0)
		push_b_down(b);
	else
		add_do_rrr_big(a, b, &best);
	return ;
}
