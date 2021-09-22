#include "../push_swap.h"

t_stack	*push_b(t_stack **stack_a, t_stack *b)
{
	lstadd_back(stack_a, b);
	b->next = NULL;
	return (b);
}