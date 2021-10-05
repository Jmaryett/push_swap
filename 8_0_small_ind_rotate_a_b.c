/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_1_finding_if_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:09 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/03 21:15:46 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_up_b_down_small(t_stack **a, t_stack **b, t_best *best)
{
	while (*a != best->tmp_a)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push_b_down(b/* , a */);
	return ;
}

void	a_down_b_up_small(t_stack **a, t_stack **b, t_best *best)
{
	while (*a != best->tmp_a)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	push_b_up(b/* , a */);
	return ;
}

void	do_rrr_small(t_stack **a, t_stack **b, t_best *best)
{
	if (best->tmp_a->moves == 0)
		push_b_down(b/* , a */);
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
		push_b_up(b/* , a */);
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

/* static void	do_rr(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	while (*a != tmp_a && *b != tmp_b)
	{
		rotate(a);
		rotate(b);
		write (1, "rr\n", 3);
	}
	if (*a != tmp_a)
	{
		while (*a != tmp_a)
		{
			rotate(a);
			write (1, "ra\n", 3);
		}
	}
	else if (*b != tmp_b)
	{
		while (*b != tmp_b)
		{
			rotate(b);
			write (1, "rb\n", 3);
		}
	}
}

static int	check_first_a_elem(t_stack *tmp_a, t_stack **a, t_stack **b)
{
	if (tmp_a->moves == 0)
	{	
		push_b_up(b, a);
		return (1);
	}
	return (0);
}

static void	a_in_second_half(t_stack **a, t_stack **b,
							t_stack *a_tmp, t_stack *tmp_a)
{
	int	len;

	len = lstsize(*a);
	while (len > len / 2)
	{
		if (a_tmp == tmp_a)
		{
			a_down_b_up(a, b, tmp_a);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	return ;
}

void	finding_if_rr(t_stack *tmp_b, t_stack **a, t_stack **b)
{
	t_stack	*a_tmp;
	t_stack	*tmp_a;
	int		len;

	tmp_a = needed_elem_in_a(a, &tmp_b);
	if (check_first_a_elem(tmp_a, a, b))
		return ;
	len = lstsize(*a) / 2;
	a_tmp = *a;
	while (len >= 0)
	{
		if (a_tmp == tmp_a)
		{
			do_rr(a, b, tmp_a, tmp_b);
			push_b_to_a(a, b);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	a_in_second_half(a, b, a_tmp, tmp_a);
}
 */