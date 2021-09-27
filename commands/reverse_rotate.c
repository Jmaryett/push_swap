#include "../push_swap.h"

void reverse_rotate(t_stack **stack)
{
 	t_stack *tmp;
	t_stack *last;
	//t_stack	*pre_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	last = *stack;
	while (last && last->next)
		last = last->next;
	last->next = *stack;
	while(tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	*stack = last;
}
