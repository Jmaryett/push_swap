#include "push_swap.h"

static void	circle_list_a(t_stack *n, t_stack *m_h)
{
	while (n->markup_head != 1 /* m_h->markup_head != 1 */)
	{
		if (m_h->number > n->number)
		{
			n->keep = 0;
			//m_h = n;
			n = n->next;
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
			//m_h = n;
			n = n->next;
		}
		else
		{
			n->keep = 1;
			m_h = n;
			n = n->next;
		}
	}
	//m_h = *a;
	n = *a; //m_h->next;
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
			//m_h = n;
			n = n->next;
		}
		else
		{
			n->keep = 1;
			m_h = n;
			n = n->next;
		}
	}
}

static void	init_count_false(t_stack **stack_a, t_count *count)
{
	t_stack	*tmp;

	tmp = *stack_a;
	count->count_false = 0;
	while (tmp)
	{
		if (tmp->keep == 0)
			count->count_false++;
		tmp = tmp->next;
	}
}

int	init_keep_in_a(t_stack **stack_a, t_stack *m_h, t_count *count)
{
	t_stack	*next_tmp;

	if (!stack_a || !*stack_a)
		return (0);
	next_tmp = m_h->next;
	if (next_tmp)
		next_isnt_null(next_tmp, m_h, stack_a);
	else if (!next_tmp)
		next_null(stack_a, m_h);
	init_count_false(stack_a, count);
	return (count->count_false);
}