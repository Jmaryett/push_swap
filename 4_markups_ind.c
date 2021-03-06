/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_markups_greater.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:31 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:47:32 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_m_h(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->markup_head = 0;
		tmp = tmp->next;
	}
}

void	init_keep_true_false(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->markup_head == 1)
			tmp->keep = 1;
		else
			tmp->keep = 0;
		tmp = tmp->next;
	}
}

static t_stack	*init_first_best_result(t_stack *t, t_count *c, t_stack **a)
{
	t->markup_head = 1;
	init_keep_true_false(a);
	c->count_false = init_keep_in_a(a, t, c);
	c->best_result = c->count_false;
	c->index_of_best_m_h = t->index;
	t->markup_head = 0;
	init_keep_true_false(a);
	t = t->next;
	return (t);
}

static void	finding_best_m_h(t_stack **stack_a, t_count *c)
{
	t_stack	*tmp;

	tmp = *stack_a;
	tmp = init_first_best_result(tmp, c, stack_a);
	while (tmp)
	{
		tmp->markup_head = 1;
		init_keep_true_false(stack_a);
		c->count_false = init_keep_in_a(stack_a, tmp, c);
		if (c->best_result > c->count_false)
		{
			c->best_result = c->count_false;
			c->index_of_best_m_h = tmp->index;
		}
		else if (c->best_result == c->count_false)
		{
			if (c->index_of_best_m_h > tmp->index)
				c->index_of_best_m_h = tmp->index;
		}
		tmp->markup_head = 0;
		init_keep_true_false(stack_a);
		tmp = tmp->next;
	}
}

void	markups(t_stack **stack_a, t_count *c)
{
	t_stack	*m_h;

	if (!stack_a || !*stack_a)
		return ;
	m_h = *stack_a;
	init_m_h(stack_a);
	finding_best_m_h(stack_a, c);
	init_m_h(stack_a);
	while (m_h->index != c->index_of_best_m_h)
		m_h = m_h->next;
	m_h->markup_head = 1;
	init_keep_true_false(stack_a);
	init_keep_in_a(stack_a, m_h, c);
}
