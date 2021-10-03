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

static void	a_down_b_up(t_stack **a, t_stack **b, t_stack *tmp_a)
{
	//rotating_a(a, *b);
	while (*a != tmp_a)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	push_b_up(b, a);
	return ;
}

static void	do_rr(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
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
