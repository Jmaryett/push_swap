#include "push_swap.h"

void	rotating_b_and_a_with_big_ind(t_stack **b, t_stack **a)
{
	int		len;
	t_stack	*tmp;

	len = lstsize(*b) / 2;
	tmp = *b;
	where_is_b(len, tmp, a, b);
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
		if ((*b)->index - tmp_a->index < (*b)->index - needed->index)
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
		}
		else
			best->tmp_b = best->tmp_b->next;
	}
	best->elem_mv->best_to_move_to_a = 1;
	return (1);
}

void	only_big_index_left(t_stack **a, t_stack **b, t_best *best)
{
	if (!*a || !*b || !a || *b)
		return ;
	while (*b)
	{
		reinit_mv_in_a(a); //need to recalculate_moves
		init_mv_in_b(b);
		if (!best_bigger_index_to_move(a, b, best))
			return ;
		rotating_b_and_a_with_big_ind(b, a);
		init_moves(a, b);
	}
}
