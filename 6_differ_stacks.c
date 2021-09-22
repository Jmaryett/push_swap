#include "push_swap.h"

 void init_markup_head(t_stack **begin)
{
	t_stack *tmp;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			tmp->markup_head = 1;
			tmp->keep = 1;
		}
		else
			tmp->markup_head = 0;
		tmp = tmp->next;
	}
}

static t_stack *find_mark_head(t_stack **begin, t_count *count)
{
	t_stack *mark_head;
	t_stack *stack_b;
	//t_stack	*tmp;

	stack_b = NULL;
	mark_head = *begin;
	while (mark_head->markup_head != 1)
		mark_head = mark_head->next;
	init_keep_in_a(begin, mark_head, count);
	stack_b = from_a_to_b(begin, &stack_b, count);
	while (*begin)
	{
		printf ("%d\n", (*begin)->number);
		*begin = (*begin)->next;
	}
	//*stack_b = keep_or_move(begin, mark_head);
	return (stack_b);
}

t_stack *differ_stacks(t_stack **begin, t_count *count)
{
	t_stack	*stack_b;

	init_markup_head(begin);
	stack_b = find_mark_head(begin, count);
	return (stack_b);
}