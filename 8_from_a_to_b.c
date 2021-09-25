#include "push_swap.h"

static int check_if_sa_needed(t_stack **stack_a, t_count *count)
{
	int prev_count;

	prev_count = count->count_false;
	swap_a(stack_a);
	markups(stack_a, count);
	if (prev_count > count->count_false)
	{
		swap_a(stack_a);
		markups(stack_a, count);
		return (1); //we need to do sa (we reversed srack a back to reverse it in general func)
	}
	else
	{
		swap_a(stack_a);
		markups(stack_a, count);
		return (0); //we don't need to do sa
	}
}

static int	do_count_false(t_stack *head)
{
	int	count_false;

	count_false = 0;
	while (head)
	{
		if (head->keep == 0)
			count_false++;
		head = head->next;
	}
	return(count_false);
}

t_stack *from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	//t_stack	*head;
	int	count_false;

	//head = *stack_a;
	count_false = do_count_false(*stack_a);
	//head = *stack_a;
	while (count_false != 0)
	{
		if (check_if_sa_needed(stack_a, count))
		{
			swap_a(stack_a);
			markups(stack_a, count);
			write(1, "sa\n", 3);
		}
		else if ((*stack_a)->keep == 0)
		{
			*stack_b = push_b(stack_a, stack_b);//top of a goes to top of b
			write(1, "pb\n", 3);
		}
		else
		{
			rotate_a(stack_a); //top goes to bot
			write(1, "ra\n", 3);
		}
		count_false = do_count_false((*stack_a));
	}
	
	return (*stack_b);
}