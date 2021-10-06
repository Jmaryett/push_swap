/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_0_small_ind_rr_rrr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:09 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 20:40:03 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	a_up_b_down_small(t_stack **a, t_stack **b, t_best *best)
{
	while (*a != best->tmp_a)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push_b_down(b);
	return ;
}

void	a_down_b_up_small(t_stack **a, t_stack **b, t_best *best)
{
	while (*a != best->tmp_a)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	push_b_up(b);
	return ;
} */

void	do_rrr_small(t_stack **a, t_stack **b, t_best *best)
{
	if (best->tmp_a->moves == 0)
		push_b_down(b);
	else
	{
		while (*a != best->tmp_a && *b != best->elem_mv) //b->best_to_move != 1
		{
			reverse_rotate(a);
			reverse_rotate(b);
			write (1, "rrr\n", 4);
		}
		if (*a != best->tmp_a)
		{
			while (*a != best->tmp_a)
			{
				reverse_rotate(a);
				write (1, "rra\n", 4);
			}
		}
		else if (*b != best->elem_mv)
		{
			while (*b != best->elem_mv)
			{
				reverse_rotate(b);
				write (1, "rrb\n", 4);
			}
		}
	}
}

void	do_rr_small(t_stack **a, t_stack **b, t_best *best)
{
	if (best->tmp_a->moves == 0)
		push_b_up(b);
	else
	{
		while (*a != best->tmp_a && *b != best->elem_mv) //b->best_to_move != 1
		{
			rotate(a);
			rotate(b);
			write (1, "rr\n", 3);
		}
		if (*a != best->tmp_a)
		{
			while (*a != best->tmp_a)
			{
				rotate(a);
				write (1, "ra\n", 3);
			}
		}
		else if (*b != best->elem_mv)
		{
			while (*b != best->elem_mv)
			{
				rotate(b);
				write (1, "rb\n", 3);
			}
		}
	}
}
