/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_0_rotating_b_and_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:03 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/01 20:39:24 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_up(t_stack **b, t_stack **a)
{
	while ((*b)->best_to_move_to_a != 1)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b_down(t_stack **b, t_stack **a)
{
	while ((*b)->best_to_move_to_a != 1)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

static void	where_is_elem_b(int len, t_stack *tmp, t_stack **a, t_stack **b)
{
	while (len / 2 > 0)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			finding_if_rr(tmp, a, b);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
	len = lstsize(*b); //была а
	while (len > len / 2)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			finding_if_rrr(tmp, a, b);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
}

void	rotating_b_and_a(t_stack **b, t_stack **a)
{
	int		len;
	t_stack	*tmp;

	len = lstsize(*b) / 2;
	tmp = *b;
	where_is_elem_b(len, tmp, a, b);
}
