#include "push_swap.h"

static void	a_down_b_up(t_stack **a, t_stack **b/* , t_moves *mv */)
{
	rotating_a(a,/*  mv,  */*b); //i could write this func here to cut lines
	push_b_up(/* mv,  */b, a);
	return ;
}

static void	do_rr(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	while(*a != tmp_a || *b != tmp_b)
	{
		rotate(a);
		rotate(b);
		write (1, "rr\n", 3);
	}
	if (*a != tmp_a)
	{
		while (*a != tmp_a)
		{
			rotate(a);
			write (1, "ra\n", 3);
		}
	}
	else if (*b != tmp_b)
	{
		while (*b != tmp_b)
		{
			rotate(b);
			write (1, "rb\n", 3);
		}
	}
}

void	finding_if_rr(t_stack *tmp_b, t_stack **a, t_stack **b/* , t_moves *mv */)
{
	t_stack	*a_tmp;
	t_stack	*tmp_a;
	int	len;

	tmp_a = needed_elem_in_a(a, &tmp_b);
	len = lstsize(*a)/2;
	a_tmp = *a;
	while(len >= 0)
	{
		if (a_tmp == tmp_a)
		{
			do_rr(a, b, tmp_a, tmp_b);
			push_b_to_a(a, b);
			return ;
		}
		else
		{
			a_down_b_up(a,/*  mv,  */b);
			return ;
		}
		a_tmp = a_tmp->next;
		len--;
	}
}