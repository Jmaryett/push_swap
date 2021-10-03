/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_from_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:58 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/03 22:14:36 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate moves to put elem to the top of 
//st b and the same for stack a after push it there
//we do this for each element in stack
// b and choose the one with least moves and move it to a

void	init_mv_in_b(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	if (len % 2 == 0)
		even_init_mv_in_b(st);
	else
	{
		while (i <= (len / 2) + 1)
		{
			tmp->moves = i;
			tmp = tmp->next;
			i++;
		}
		while (i >= 2 && tmp)
		{
			i--;
			tmp->moves = i;
			tmp = tmp->next;
		}
	}
}

static void	init_mv_in_a(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = (*st)->next;
	if (len % 2 == 0)
		even_init_mv_in_a(st);
	else
	{
		while (i <= len / 2)
		{
			tmp->moves = i;
			tmp = tmp->next;
			i++;
		}
		while (i > 1 && tmp)
		{
			i--;
			tmp->moves = i;
			tmp = tmp->next;
		}
	}
}

t_stack	*needed_elem_in_a(t_stack **a, t_stack **b)
{
	t_stack	*needed;
	t_stack	*tmp_a;
	int		count;

	if (!a || !b)
		return (NULL);
	tmp_a = *a;
	needed = tmp_a;
	count = 0;
	while (tmp_a)
	{
		if (tmp_a->index < (*b)->index)
			tmp_a = tmp_a->next;
		else if (tmp_a->index - (*b)->index < needed->index - (*b)->index)
		{
			needed = tmp_a;
			tmp_a = tmp_a->next;
			count = 1;
		}
		else
			tmp_a = tmp_a->next;
	}
	if (count == 0)
		return (NULL);
	return (needed);
}

//here i find best elem in b to move to a
//if tje only left elem in b has the biggest index
//i find smaller index for it, recalculate moves, push it both down and up
//then push from b to a AND I QUIT all functions back to func from_b_to_a

static int	calculate_moves(t_stack **a, t_stack **b, t_best *best)
{
	t_stack	*tmp_b = *b;

	while (tmp_b)
	{
		if (!(init_first_best_elem(best, b, a)))
			tmp_b = tmp_b->next;
		else
			break ;
	}
	if (tmp_b == NULL)
	{
		only_big_index_left(a, b, best);
		return (0);
	}
	while (best->tmp_b)
	{
		best->tmp_a = needed_elem_in_a(a, &best->tmp_b);
		if (!best->tmp_a)
			best->tmp_b = best->tmp_b->next;
		else if (best->tmp_b->moves + best->tmp_a->moves < best->min)
		{
			best->min = best->tmp_a->moves + best->tmp_b->moves;
			best->elem_mv = best->tmp_b;
		}
		else if (best->tmp_b->moves + best->tmp_a->moves == best->min)
		{
			if (best->tmp_b->index < best->elem_mv->index)
				best->elem_mv = best->tmp_b;
		}
		else
			best->tmp_b = best->tmp_b->next;
	}
	best->elem_mv->best_to_move_to_a = 1;
	printf("index is %d, it's index in a is %d\n", best->elem_mv->index, best->tmp_a->index);
	return (1);
}

void	from_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_best	best;

	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	while (*stack_b)
	{
		//sort_a(stack_a);
		init_mv_in_a(stack_a);
		init_mv_in_b(stack_b);
		if (!calculate_moves(stack_a, stack_b, &best))
			return ;
		rotating_b_and_a(stack_b, stack_a);
		init_moves(stack_a, stack_b);
	}
}
