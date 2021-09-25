#include "push_swap.h"

static t_stack	*circle_list(t_stack *n, t_stack *m_h, t_stack *b)
{
	while (m_h->markup_head != 1)
	{
		if (m_h->number > n->number)
		{
			m_h->next = n->next;
			lstadd_back(&b, n);
			n->next = NULL;
			n = m_h->next;
		}
		else
		{
			m_h = m_h->next;
			n = n->next;
		}
	}
	return (b);
}

static t_stack	*next_is_not_null(t_stack *n, t_stack *m_h, t_stack *b, t_stack **a)
{
	while (n)
	{
		if (m_h->number > n->number)
		{
			m_h->next = n->next;
			lstadd_back(&b, n);
			n->next = NULL;
			n = m_h->next;
		}
		else
		{
			m_h = n;
			n = n->next;
		}
	}
	m_h = *a;
	n = m_h->next;
	b = circle_list(n, m_h, b);
	return (b);
}

static t_stack	*next_is_null(t_stack **a, t_stack *m_h, t_stack *b)
{
	t_stack	*n;

	n = *a;
	while (n && n->markup_head != 1)
	{
		if (m_h->number > n->number)
		{
			m_h->next = n->next;
			lstadd_back(&b, n);
			n->next = NULL;
			n = m_h->next;
		}
		else
		{
			m_h = n;
			n = n->next;
		}
	}
	return (b);
}

//m_h is a markup head
t_stack	*keep_or_move(t_stack **begin, t_stack *m_h)
{
	t_stack	*next_tmp;
	t_stack	*stack_b;

	stack_b = NULL;
	next_tmp = m_h->next;
	if (next_tmp)
		stack_b = next_is_not_null(next_tmp, m_h, stack_b, begin);
	else if (!next_tmp)
		stack_b = next_is_null(begin, m_h, stack_b);
	return (stack_b);
}
