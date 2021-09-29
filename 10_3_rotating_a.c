#include "push_swap.h"

void	push_a_up(t_stack **a, t_stack *tmp_a/* , t_moves *mv */)
{
	while (*a != tmp_a)
	{
		rotate(a);
		/* mv->count_moves++; */
		write(1, "ra\n", 3);
	}
}

void	push_a_down(t_stack **a, t_stack *tmp_a/* , t_moves *mv */)
{
	while (*a != tmp_a)
	{
		reverse_rotate(a);
		/* mv->count_moves++; */
		write(1, "rra\n", 4);
	}
}

void	rotating_a(t_stack **a,/*  t_moves *mv,  */t_stack *b)
{
	t_stack *tmp_a;
	t_stack	*tmp;
	int	len;

	tmp = *a;
	tmp_a = needed_elem_in_a(a, &b);
	len = lstsize(*a) / 2;
	while (len >= 0)
	{
		if (tmp == tmp_a)
		{
			push_a_up(a, tmp_a/* , mv */);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
	len = lstsize(*a);
	while (len > lstsize(*a)/2)
	{
		if (tmp == tmp_a)
		{
			push_a_down(a, tmp_a/* , mv */);
			return ;
		}
		tmp = tmp->next;
		len--;
	}
}