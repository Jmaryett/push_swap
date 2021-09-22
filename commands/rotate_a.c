#include "../push_swap.h"

void rotate_a(t_stack **stack_a/* , t_count *count */)
{
	t_stack *current;
	t_stack *next_node;
	t_stack	*prev;
	//t_stack	*m_h;

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
	*stack_a = prev;
/* 	m_h = *stack_a;
	init_markup_head(stack_a);
	while (m_h->markup_head != 1)
		m_h = m_h->next;
	init_keep_in_a(stack_a, m_h, count); */
}