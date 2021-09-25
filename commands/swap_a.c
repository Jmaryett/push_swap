#include "../push_swap.h"

void swap_a(t_stack **stack_a)
{
	t_stack *next_a;

	if (!stack_a || !*stack_a)
		return ;
	next_a = (*stack_a)->next;
	(*stack_a)->next = next_a->next;
	next_a->next = *stack_a;
	*stack_a = next_a;
}
