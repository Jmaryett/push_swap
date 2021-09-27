#include "../push_swap.h"

void rotate(t_stack **stack)
{
 	t_stack *tmp;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last && last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}
