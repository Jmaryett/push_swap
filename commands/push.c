#include "../push_swap.h"

static void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	tmp = *stack_1;
	if (!stack_1 || !*stack_1)
		return (NULL);
	else if (!stack_2 || !*stack_2)
	{
		*stack_2 = *stack_1;
		*stack_1 = (*stack_1)->next;
		(*stack_2)->next = NULL;
	}
	else
	{
		*stack_1 = (*stack_1)->next;
		lstadd_front(stack_2, tmp);
	}
	return (*stack_2);
}