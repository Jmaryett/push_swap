#include "push_swap.h"

void	even_init_mv_in_b(t_stack **st)
{
	int len;
	int i;
	t_stack *tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	if (len == 2)
	{
		tmp->moves = 1;
		tmp->next->moves = 2;
		return ;
	}
	while (i <= len / 2)
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

void	even_init_mv_in_a(t_stack **st)
{
	int len;
	int i;
	t_stack *tmp;

	i = 1;
	len = lstsize(*st);
	tmp = (*st)->next;
	while (i < len / 2)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i++;
	}
	while (i >= 1 && tmp)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i--;
	}
}
/* t_stack	*best_elem_in_b(t_stack *tmp_b, t_stack *tmp_a, t_stack **a, int min)
{
	t_stack	*best;

	best = NULL;
	while (tmp_b)
	{
		tmp_a = needed_elem_in_a(a, &tmp_b);
		if (tmp_b->moves + tmp_a->moves < min)
		{
			min = tmp_a->moves + tmp_b->moves;
			best = tmp_b;
		}
		else if (tmp_b->moves + tmp_a->moves == min)
		{
			if (tmp_b->index < best->index)
				best = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	return (best);
} */