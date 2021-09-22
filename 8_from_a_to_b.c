#include "push_swap.h"

t_stack *swap_a(t_stack **stack_a, t_count *count)
{
	t_stack *next_a;
	t_stack *m_h;

	next_a = (*stack_a)->next;
	(*stack_a)->next = next_a->next;
	next_a->next = *stack_a;
	*stack_a = next_a;
	m_h = *stack_a;
	init_markup_head(stack_a);
	while (m_h->markup_head != 1)
		m_h = m_h->next;
	init_keep_in_a(stack_a, m_h, count); //check how many nbrs will stay in stack after sa
	return (*stack_a);
}

int check_if_sa_needed(t_stack *stack_a, t_count *count)
{
	t_stack	*m_h; //markup_head of tmp after sa
	int prev_count;

	prev_count = count->count_keep;
	m_h = stack_a;
	stack_a = swap_a(&stack_a, count);
	init_markup_head(&stack_a);
	if (prev_count > count->count_keep)
	{
		write(1, "sa", 2);
		return (1);
	}
	else
	{
		count->count_keep = 0;
		stack_a = swap_a(&stack_a, count); //do sa
		init_markup_head(&stack_a);//find new mark head
		m_h = stack_a;
		while (m_h->markup_head != 1)
		m_h = m_h->next;
		init_keep_in_a(&stack_a, m_h, count); //renew markup
		return (0);
	}
}

t_stack *from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	t_stack	*head;

	while ((*stack_a))
	{
		if (check_if_sa_needed(stack_a, count))
			continue ;
		else if ((*stack_a)->keep == 0)
			*stack_b = push_b(stack_a, *stack_b);
		else
			rotate_a(stack_a);
	}
	return (*stack_b);
}