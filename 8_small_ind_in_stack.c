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

//1 is a is in first half (ra), 0 is in the second half (rra)
int	where_is_b(int len, t_stack **b, t_best *best)
{
	t_stack	*b_new;

	b_new = *b;
	while (len >= 0 && b_new)
	{
		if (b_new == best->elem_mv || b_new->best_to_move_to_a == 1)
			return (1);
		b_new = b_new->next;
	}
	return (0);
}

//1 is a is in first half (ra), 0 is in the second half (rra)
int	where_is_a(int len, t_stack **a, t_best *best)
{
	t_stack	*a_new;

	a_new = *a;
	while (len >= 0 && a_new)
	{
		if (a_new == best->tmp_a)
			return (1);
		a_new = a_new->next;
	}
	return (0);
}

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

/* static void	where_is_elem_b(int len, t_stack *tmp, t_stack **a, t_stack **b)
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
} */

void	rotating_b_and_a_with_small_ind(t_stack **b, t_stack **a, t_best *best)
{
	int		i_a;
	int		j_b;
	int		len_b;
	int		len_a;
	//t_stack	*tmp;

	len_b = lstsize(*b) / 2;
	len_a = lstsize(*a) / 2;
	j_b = where_is_b(len_b, b, best);
	i_a = where_is_a(len_a, a, best);
	if (i_a == 0 && j_b == 0)
		do_rrr_small(a, b, best);
	else if (i_a == 1 && j_b == 0)
		a_up_b_down_small(a, b, best);
	else if (i_a == 0 && j_b == 1)
		a_down_b_up_small(a, b, best);
	else if (i_a == 1 && j_b == 1)
		do_rr_small(a, b, best);
	push_b_to_a(a, b);
}