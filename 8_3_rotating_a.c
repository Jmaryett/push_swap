/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_3_rotating_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:23 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 18:29:26 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_up(t_stack **a, t_stack *tmp_a)
{
	while (*a != tmp_a)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	push_a_down(t_stack **a, t_stack *tmp_a)
{
	while (*a != tmp_a)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

static void	a_in_second_part(t_stack **a, t_stack *tmp, t_stack *tmp_a)
{
	int	len;

	len = lstsize(*a);
	while (len > lstsize(*a) / 2)
	{
		if (tmp == tmp_a)
		{
			push_a_down(a, tmp_a);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
	return ;
}

void	rotating_a(t_stack **a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp;
	int		len;

	tmp = *a;
	tmp_a = needed_elem_in_a(a, &b);
	len = lstsize(*a) / 2;
	while (len >= 0)
	{
		if (tmp == tmp_a)
		{
			push_a_up(a, tmp_a);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
	a_in_second_part(a, tmp, tmp_a);
}
