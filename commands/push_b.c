#include "../push_swap.h"

static void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (!stack_a || !*stack_a)
		return (NULL);
	else if (!stack_b || !*stack_b)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		*stack_a = (*stack_a)->next;
		lstadd_front(stack_b, tmp);
	}
	return (*stack_b);
}