#include "push_swap.h"

static void init_mv_in_b(t_stack **st)
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
		return;
	}
	while (i <= (len/2)+1)
	{
		tmp->moves += i;
		tmp = tmp->next;
		i++;
	}
	while (len > i)
	{
		tmp->moves = len - i;
		tmp = tmp->next;
		len--;
	}
	//calculate moves to put elem to the top of st b and the same for stack a after push it there
	//we do this for each element in stack b and choose the one with least moves and move it to a
}

static void init_mv_in_a(t_stack **st)
{
	int len;
	int i;
	t_stack *tmp;

	i = 1;
	len = lstsize(*st);
	tmp = (*st)->next;
	if (len == 2)
	{
		tmp->moves = 1;
		return;
	}
	while (i <= len / 2)
	{
		tmp->moves += i;
		tmp = tmp->next;
		i++;
	}
	while (len > i)
	{
		tmp->moves = len - i;
		tmp = tmp->next;
		len--;
	}
	//calculate moves to put elem to the top of st b and the same for stack a after push it there
	//we do this for each element in stack b and choose the one with least moves and move it to a
}

t_stack *needed_elem_in_a(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		if (tmp_b->index + 1 == tmp_a->index)
			return (tmp_a);
		tmp_a = tmp_a->next;
	}
	return (NULL);
}

//here i find best elem in b to move to a
static void calculate_moves(t_stack **a, t_stack **b)
{
	//we need to sum using indexes and moves of that index
	//also we calculate the index in b and its NEXT index in a
	t_stack *tmp_a;
	t_stack *tmp_b;
	t_stack	*best;
	int min;

	tmp_b = *b;
	tmp_a = needed_elem_in_a(a, &tmp_b);
	min = tmp_b->moves + tmp_a->moves;
	best = tmp_b;
	tmp_b = tmp_b->next;
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
	best->best_to_move_to_a = 1;
}

void from_b_to_a(t_stack **stack_b, t_stack **stack_a, t_moves *mv)
{
	//first i need to move elems in st_a to sirt it(while index of *st_a != 0 we rotate_a)
	//maybe i can sort stack b too
	//sort_a(stack_a, mv);
	//all below should be in loop
	while (*stack_b)
	{
		init_mv_in_a(stack_a);
		init_mv_in_b(stack_b);
		calculate_moves(stack_a, stack_b); //this is where we found best elem
		rotating_b_and_a(stack_b, mv, stack_a); //here we should rotate b, rotate a and then push best elem to a
	}
	while (*stack_b)
	{
		printf("index = %d, mvs for it = %d\n", (*stack_b)->index, (*stack_b)->moves);
		*stack_b = (*stack_b)->next;
	}
	printf("Count of mvs in a\n");
	while (*stack_a)
	{
		printf("index = %d, mvs for it = %d\n", (*stack_a)->index, (*stack_a)->moves);
		*stack_a = (*stack_a)->next;
	}
}