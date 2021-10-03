/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_2_b_is_in_second_half.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:54:14 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/03 21:15:00 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_up_b_down(t_stack **a, t_stack **b, t_stack *tmp_a)
{
	t_stack	*first_should_be;

	first_should_be = tmp_a->next;
	while (*a != first_should_be)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push_b_down(b, a);
	return ;
}

static void	a_is_in_first_half(t_stack **a, t_stack **b,
							t_stack *a_tmp, t_stack *tmp_a)
{
	int	len;

	len = lstsize(*b) / 2;
	while (len >= 0)
	{
		if (a_tmp == tmp_a)
		{
			a_to_up_b_down(a, b, tmp_a);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	return ;
}

static void	make_rrr(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	t_stack	*first_should_be;
	
	first_should_be = tmp_a->next;
	while (*a != first_should_be && *b != tmp_b)
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
	else if (*b != tmp_b)
	{
		while (*b != tmp_b)
		{
			reverse_rotate(b);
			write (1, "rrb\n", 3);
		}
	}
}

static int	check_if_a_elem_last(t_stack *tmp_a, t_stack **a, t_stack **b)
{
	t_stack	*a_new;
	
	a_new = *a;
	while (a_new->next)
		a_new = a_new->next;
	if (a_new->next = tmp_a)
	{
		push_b_down(b, a);
		return (1);
	}
	return (0);
}

void	check_rrr(t_stack *tmp_b, t_stack **a, t_stack **b)
{
	t_stack	*a_tmp;
	t_stack	*tmp_a;
	int		len;

	tmp_a = smaller_index_for_b(a, &tmp_b);
	len = lstsize(*a);
	a_tmp = *a;
	if (check_if_a_elem_last(tmp_a, a, b))
		return ;
	while (len > len / 2)
	{
		if (a_tmp == tmp_a)
		{
			make_rrr(a, b, tmp_a, tmp_b);
			push_b_to_a(a, b);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	a_is_in_first_half(a, b, a_tmp, tmp_a);
}