/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:50:39 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:50:40 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*next_a;

	if (!stack || !*stack ||!(*stack)->next)
		return ;
	next_a = (*stack)->next;
	(*stack)->next = next_a->next;
	next_a->next = *stack;
	*stack = next_a;
}
