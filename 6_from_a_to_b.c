/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_from_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:46 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:56:19 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_sa_needed(t_stack **stack_a, t_count *count)
{
	int	prev_count;

	prev_count = count->count_false;
	swap(stack_a);
	markups(stack_a, count);
	if (prev_count > count->count_false)
	{
		swap(stack_a);
		markups(stack_a, count);
		return (1);
	}
	else
	{
		swap(stack_a);
		markups(stack_a, count);
		return (0);
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
	return (count_false);
}

static void	do_sa(t_stack **stack_a, t_count *c)
{
	swap(stack_a);
	markups(stack_a, c);
	write(1, "sa\n", 3);
}

t_stack	*from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_count *c)
{
	int	count_false;

	if (!stack_a || !*stack_a)
		return (NULL);
	count_false = do_count_false(*stack_a);
	while (count_false != 0)
	{
		if (check_if_sa_needed(stack_a, c))
			do_sa(stack_a, c);
		else if ((*stack_a)->keep == 0)
		{
			*stack_b = push(stack_a, stack_b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		count_false = do_count_false((*stack_a));
	}
	return (*stack_b);
}
