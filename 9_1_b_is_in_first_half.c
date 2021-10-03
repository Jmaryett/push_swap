/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_1_b_is_in_first_half.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:32:51 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/03 21:16:25 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_down_b_up(t_stack **a, t_stack **b, t_stack *tmp_a)
{
	t_stack	*first_should_be;

	first_should_be = tmp_a->next;
	while (*a != first_should_be)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	push_b_up(b, a);
	return ;
}

static void	a_is_in_second_half(t_stack **a, t_stack **b,
							t_stack *a_tmp, t_stack *tmp_a)
{
	int	len;

	len = lstsize(*a);
	while (len > len / 2)
	{
		if (a_tmp == tmp_a)
		{
			a_to_down_b_up(a, b, tmp_a);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	return ;
}

static int	check_if_a_elem_is_last(t_stack *tmp_a, t_stack **a, t_stack **b)
{
	t_stack	*a_new;
	
	a_new = *a;
	while (a_new->next)
		a_new = a_new->next;
	if (a_new->next = tmp_a)
	{
		push_b_up(b, a);
		return (1);
	}
	return (0);
}

static void	make_rr(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	t_stack	*first_should_be;

	first_should_be = tmp_a->next;
	while (*a != first_should_be && *b != tmp_b)
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
	else if (*b != tmp_b)
	{
		while (*b != tmp_b)
		{
			rotate(b);
			write (1, "rb\n", 3);
		}
	}
}

//here i need to look if a is already on bottom
//beause i don't need to push it on top
//i need to push it to bottom and then put elem b

static void	check_rr(t_stack *tmp_b, t_stack **a, t_stack **b)
{
	t_stack	*a_tmp;
	t_stack	*tmp_a;
	int		len;

	tmp_a = smaller_index_for_b(a, &tmp_b);
	if (check_if_a_elem_is_last(tmp_a, a, b))
		return ;
	len = lstsize(*a) / 2;
	a_tmp = *a;
	while (len >= 0)
	{
		if (a_tmp == tmp_a)
		{
			make_rr(a, b, tmp_a, tmp_b);
			push_b_to_a(a, b);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
	a_is_in_second_half(a, b, a_tmp, tmp_a);
}

//тут если б в первой половине, мы проверяем, также ли его а в первой половине
//если нет, то мы пушим их по-отдельности, если да - одновременно, 
//пока а не окажется последним элементом
//и, соответственно, наоборот
void	where_is_b(int len, t_stack *tmp, t_stack **a, t_stack **b)
{
	while (len / 2 > 0)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			check_rr(tmp, a, b);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
	len = lstsize(*b);
	while (len > len / 2)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			check_rrr(tmp, a, b);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
}