#include "push_swap.h"

/* static void	push_b_up(t_moves *mv, t_stack **b, t_stack **a)
{
	while ((*b)->best_to_move_to_a != 1)
	{
		rotate(b);
		mv->count_moves++;
		write(1, "rb\n", 3);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

static void	push_b_down(t_moves *mv, t_stack **b, t_stack **a)
{
	while ((*b)->best_to_move_to_a != 1)
	{
		reverse_rotate(b);
		mv->count_moves++;
		write(1, "rrb\n", 4);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	rotating_b_and_a(t_stack **b, t_moves *mv, t_stack **a)
{
	int	len;
	t_stack	*tmp;

	len = lstsize(*b)/2;
	tmp = *b;
	while(len >= 0)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			rotating_a(a, mv, tmp);
			push_b_up(mv, b, a);
			return;
		}
		tmp = tmp->next;
		len--;
	}
	len = lstsize(*b);
	while (len > len/2)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			rotating_a(a, mv, tmp);
			push_b_down(mv, b, a);
			return;
		}
		tmp = tmp->next;
		len--;
	}
} */

void	push_b_up(/* t_moves *mv, */ t_stack **b, t_stack **a)
{
	while ((*b)->best_to_move_to_a != 1)
	{
		rotate(b);
		/* mv->count_moves++; */
		write(1, "rb\n", 3);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b_down(/* t_moves *mv, */ t_stack **b, t_stack **a)
{
	while ((*b)->best_to_move_to_a != 1)
	{
		reverse_rotate(b);
		/* mv->count_moves++; */
		write(1, "rrb\n", 4);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	rotating_b_and_a(t_stack **b,/*  t_moves *mv,  */t_stack **a)
{
	int	len;
	t_stack	*tmp;

	len = lstsize(*b)/2;
	tmp = *b;
	while(len/2 >= 0)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			finding_if_rr(tmp, a, b/* , mv */);
			//push_b_up(mv, b, a);
			return;
		}
		tmp = tmp->next;
		len--;
	}
	len = lstsize(*b);
	while (len > len/2)
	{
		if (tmp->best_to_move_to_a == 1)
		{
			finding_if_rrr(tmp, a, b);
			//rotating_a(a,/*  mv,  */tmp);
			//push_b_down(/* mv,  */b, a);
			return;
		}
		tmp = tmp->next;
		len--;
	}
}