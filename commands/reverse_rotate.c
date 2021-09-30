/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:50:27 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:51:50 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last && last->next)
		last = last->next;
	last->next = *stack;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	*stack = last;
}
