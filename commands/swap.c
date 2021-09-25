#include "../push_swap.h"

void swap(t_stack **stack)
{
	t_stack *next_a;

	if (!stack || !*stack ||!(*stack)->next)
		return ;
	next_a = (*stack)->next;
	(*stack)->next = next_a->next;
	next_a->next = *stack;
	*stack = next_a;
}
