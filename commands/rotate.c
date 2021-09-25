#include "../push_swap.h"

/* static t_stack	*find_pre_last(t_stack **a)
{
	t_stack	*pre;
	int	len;
	int	i;

	len = lstsize(*a);
	pre = *a;
	i = 0;
	while (i < len - 2 && pre && pre->next)
	{
		pre = pre->next;
		i++;
	}
	return (pre);
} */

void rotate(t_stack **stack)
{
 	t_stack *tmp;
	t_stack *last;
	//t_stack	*pre_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last && last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;

/*	last = (*stack_a)->next;
	while (last && last->next)
		last = last->next;
	pre_last = find_pre_last(stack_a);
	tmp = *stack_a;
	*stack_a = last;
	(*stack_a)->next = tmp->next;
	last = tmp;
	last->next = NULL;
	pre_last->next = last; */

	/* 	t_stack *current;
	t_stack *next_node;
	t_stack	*prev;

	prev = NULL;
	next_node = NULL;
	current = *stack_a;
	while (current != NULL)
	{
		next_node = current->next;
		current->next = prev;
		prev = current;
		current = next_node;
	}
	*stack_a = prev; */
}
