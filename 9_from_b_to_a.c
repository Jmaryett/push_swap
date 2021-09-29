#include "push_swap.h"

//calculate moves to put elem to the top of st b and the same for stack a after push it there
//we do this for each element in stack b and choose the one with least moves and move it to a
static void init_mv_in_b(t_stack **st)
{
	int len;
	int i;
	t_stack *tmp;

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

static void init_mv_in_a(t_stack **st)
{
	int len;
	int i;
	t_stack *tmp;

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

t_stack *needed_elem_in_a(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		if (tmp_b->index < tmp_a->index)
			return (tmp_a);
		tmp_a = tmp_a->next;
	}
	return (NULL);
}

//here i find best elem in b to move to a
//we need to sum using indexes and moves of that index
//also we calculate the index in b and its NEXT index in a
static void calculate_moves(t_stack **a, t_stack **b, t_best *best)
{
/* 	t_stack *tmp_a;
	t_stack *tmp_b;
	t_stack *best;
	int min;
 */
	best->tmp_b = *b;
	best->tmp_a = needed_elem_in_a(a, &best->tmp_b);
	best->min = best->tmp_b->moves + best->tmp_a->moves;
	best->elem_mv = best->tmp_b;
	best->tmp_b = best->tmp_b->next;
	while (best->tmp_b)
	{
		best->tmp_a = needed_elem_in_a(a, &best->tmp_b);
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
		best->tmp_b = best->tmp_b->next;
	}
	best->elem_mv->best_to_move_to_a = 1;
}

void from_b_to_a(t_stack **stack_b, t_stack **stack_a/* , t_moves *mv */)
{
	t_best	best;

	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	while (*stack_b)
	{
		init_mv_in_a(stack_a);
		init_mv_in_b(stack_b);
		calculate_moves(stack_a, stack_b, &best);		//this is where we found best elem
		rotating_b_and_a(stack_b,/*  mv,  */stack_a); //here we should rotate b, rotate a and then push best elem to a
		init_moves(stack_a, stack_b);
	}
}