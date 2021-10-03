/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_2_finding_if_rrr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:14 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/03 21:11:26 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_up_b_down(t_stack **a, t_stack **b, t_stack *tmp_a)
{
	//rotating_a(a,*b);
	while (*a != tmp_a)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push_b_down(b, a);
	return ;
}

static void	do_rrr(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	while (*a != tmp_a && *b != tmp_b)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write (1, "rrr\n", 4);
	}
	if (*a != tmp_a)
	{
		while (*a != tmp_a)
		{
			reverse_rotate(a);
			write (1, "rra\n", 4);
		}
	}
	else if (*b != tmp_b)
	{
		while (*b != tmp_b)
		{
			reverse_rotate(b);
			write (1, "rrb\n", 3);
		}
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

static void	a_in_first_half(t_stack **a, t_stack **b,
							t_stack *a_tmp, t_stack *tmp_a)
{
	int		len;

	len = lstsize(*b) / 2;
	while (len >= 0)
	{
		if (a_tmp == tmp_a)
		{
			a_up_b_down(a, b, tmp_a);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	return ;
}

void	finding_if_rrr(t_stack *tmp_b, t_stack **a, t_stack **b)
{
	t_stack	*a_tmp;
	t_stack	*tmp_a;
	int		len;

	tmp_a = needed_elem_in_a(a, &tmp_b);
	len = lstsize(*a);
	a_tmp = *a;
	if (tmp_a->moves == 0)
	{
		push_b_down(b, a);
		return ;
	}
	while (len > len / 2)
	{
		if (a_tmp == tmp_a)
		{
			do_rrr(a, b, tmp_a, tmp_b);
			push_b_to_a(a, b);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	a_in_first_half(a, b, a_tmp, tmp_a);
}
