#include "push_swap.h"

static void	circle_list_a(t_stack *n, t_stack *m_h)
{
	while (m_h->markup_head != 1)
	{
		if (m_h->number > n->number)
		{
			n->keep = 0;
			m_h = n;
			n = m_h->next;
		}
		else
		{
			n->keep = 1;
			m_h = n;
			n = n->next;
		}
	}
}

static void	next_isnt_null(t_stack *n, t_stack *m_h, t_stack **a)
{
	while (n)
	{
		if (m_h->number > n->number)
		{
			n->keep = 0;
			m_h = n;
			n = m_h->next;
		}
		else
		{
			n->keep = 1;
			m_h = n;
			n = n->next;
		}
	}
	m_h = *a;
	n = m_h->next;
	circle_list_a(n, m_h);
}

static void	next_null(t_stack **a, t_stack *m_h)
{
	t_stack	*n;

	n = *a;
	while (n && n->markup_head != 1)
	{
		if (m_h->number > n->number)
		{
			n->keep = 0;
			m_h = n;
			n = m_h->next;
		}
		else
		{
			n->keep = 1;
			m_h = n;
			n = n->next;
		}
	}
}

static void	init_count_keep(t_stack **stack_a, t_count *count)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->keep == 0)
			count->count_keep++;
		tmp = tmp->next;
	}
}

void	init_keep_in_a(t_stack **stack_a, t_stack *m_h, t_count *count)
{
	t_stack	*next_tmp;

	next_tmp = m_h->next;
	if (next_tmp)
		next_isnt_null(next_tmp, m_h, stack_a);
	else if (!next_tmp)
		next_null(stack_a, m_h);
	init_count_keep(stack_a, count);
}