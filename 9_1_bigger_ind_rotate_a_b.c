/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_2_b_is_in_second_half.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:54:14 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/04 19:31:32 by jmaryett         ###   ########.fr       */
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
	push_b_down(b/* , a */);
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
	push_b_up(b/* , a */);
	return ;
}

/* static void	a_is_in_first_half(t_stack **a, t_stack **b,
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
	if (a_new == tmp_a)
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

	//wrong condition if a is in second half or in first
	tmp_a = smaller_index_for_b(a, &tmp_b);
	len = lstsize(*a) / 2;
	a_tmp = *a;
	if (check_if_a_elem_last(tmp_a, a, b))
		return ;
	while (len >= 0)
	{
		if (a_tmp == tmp_a)
		{
			a_is_in_first_half(a, b, a_tmp, tmp_a);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	make_rrr(a, b, tmp_a, tmp_b);
	push_b_to_a(a, b);
	return ;
} */

void	do_rr(t_stack **a, t_stack **b, t_best *best)
{
	t_stack	*first_should_be;

	first_should_be = best->tmp_a->next;
	if (best->tmp_a->moves == 0)
		push_b_up(b/* , a */);
	else
	{
		while (*a != first_should_be && *b != best->elem_mv) //b->best_to_move != 1
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

void	do_rrr(t_stack **a, t_stack **b, t_best *best)
{
	t_stack	*first_should_be;

	first_should_be = best->tmp_a->next;
	if (best->tmp_a->moves == 0)
		push_b_down(b/* , a */);
	else
	{
		while (*a != first_should_be && *b != best->elem_mv) //b->best_to_move != 1
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