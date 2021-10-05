#include "push_swap.h"

/* //1 is a is in first half (ra), 0 is in the second half (rra)
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
} */


void	rotating_b_and_a_with_big_ind(t_stack **b, t_stack **a, t_best *best)
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
		do_rrr(a, b, best);
	else if (i_a == 1 && j_b == 0)
		a_to_up_b_down(a, b, best);
	else if (i_a == 0 && j_b == 1)
		a_to_down_b_up(a, b, best);
	else if (i_a == 1 && j_b == 1)
		do_rr(a, b, best);
	push_b_to_a(a, b);
}

//here i find suitable index from a to left big index in b

t_stack	*smaller_index_for_b(t_stack **a, t_stack **b)
{
	t_stack	*needed;
	t_stack	*tmp_a;
	int	count;

	if (!a || !*a || !b)
		return (NULL);
	count = 0;
	tmp_a = *a;
	needed = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->index > (*b)->index)
			tmp_a = tmp_a->next;
		else if ((*b)->index - tmp_a->index < 0 || (*b)->index - needed->index < 0)
			needed = tmp_a->next;
		else if ((*b)->index - tmp_a->index < (*b)->index - needed->index ||
			(*b)->index - tmp_a->index == (*b)->index - needed->index)
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

//here i just initiate first best elem to move to a for comparing

int	init_first_best_bigger_ind_to_move(t_best *best, t_stack **b, t_stack **a)
{
	best->tmp_b = *b;
	best->tmp_a = smaller_index_for_b(a, &best->tmp_b);
	if (!best->tmp_a)
		return (0);
	best->min = best->tmp_b->moves + best->tmp_a->moves;
	best->elem_mv = best->tmp_b;
	best->tmp_b = best->tmp_b->next;
	return (1);
}

//here i find best bigger index left in b

int	best_bigger_index_to_move(t_stack **a, t_stack **b, t_best *best)
{
	if (!init_first_best_bigger_ind_to_move(best, b, a))
		return (0);
	while (best->tmp_b)
	{
		best->tmp_a = smaller_index_for_b(a, &best->tmp_b);
		if (best->tmp_b->moves + best->tmp_a->moves < best->min)
		{
			best->min = best->tmp_a->moves + best->tmp_b->moves;
			best->elem_mv = best->tmp_b;
		}
		else if (best->tmp_b->moves + best->tmp_a->moves == best->min)
		{
			if (best->tmp_b->index < best->elem_mv->index)
				best->elem_mv = best->tmp_b;
			best->tmp_b = best->tmp_b->next;
		}
		else
			best->tmp_b = best->tmp_b->next;
	}
	best->elem_mv->best_to_move_to_a = 1;
	best->tmp_a = smaller_index_for_b(a, &best->elem_mv);
	return (1);
}

void	only_big_index_left(t_stack **a, t_stack **b, t_best *best)
{
	if (!a || !b)
		return ;
	while (*b)
	{
		reinit_mv_in_a(a); //need to recalculate_moves
		init_mv_in_b(b);
		if (!best_bigger_index_to_move(a, b, best))
			return ;
		rotating_b_and_a_with_big_ind(b, a, best);
		init_moves(a, b);
	}
}
