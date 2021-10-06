/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:41 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 20:51:05 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	init_moves(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_a->moves = 0;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->moves = 0;
		tmp_b->best_to_move_to_a = 0;
		tmp_b = tmp_b->next;
	}
} */

int	where_is_min_ind(t_stack **a, int min)
{
	int		len;
	t_stack	*tmp_a;
	
	tmp_a = *a;
	len = lstsize(*a) / 2;
	while (len >= 0)
	{
		if (tmp_a->index == min)
			return (1);
		tmp_a = tmp_a->next;
		len--;
	}
	return (0);
}

void	sort_a(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	if (where_is_min_ind(stack_a, min))
	{
		while ((*stack_a)->index != min)
		{
			rotate(stack_a);
			write (1, "ra\n", 3);
		}
	}
	else
	{
		while ((*stack_a)->index != min)
		{
			reverse_rotate(stack_a);
			write (1, "rra\n", 4);
		}
	}
}
	

static void	b_is_empty(t_stack **a)
{
	sort_a(a);
	exit(0);
}

static void	starting_to_push(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_count	count;

	if (!stack_a || !*stack_a)
		return ;
	stack_b = NULL;
	count.count_false = 0;
	indexation(stack_a);
	markups(stack_a, &count);
	stack_b = from_a_to_b(stack_a, &stack_b, &count);
	if (!stack_b)
		b_is_empty(stack_a);
	init_moves(stack_a, &stack_b);
	from_b_to_a(&stack_b, stack_a);
	free_memory_lst(stack_b);
	sort_a(stack_a);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = parse_and_validate_input(argc, argv);
	if (!stack_a)
		exit(1);
	starting_to_push(&stack_a);
	free_memory_lst(stack_a);
	exit (1);
}
