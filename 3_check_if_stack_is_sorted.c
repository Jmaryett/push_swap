/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_check_if_stack_is_sorted.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:11 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:47:12 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_stack_is_sorted(t_stack **begin)
{
	t_stack	*prev;
	t_stack	*nex;

	if (!begin || !*begin)
		return ;
	prev = *begin;
	nex = prev->next;
	while (nex)
	{
		if (nex->number > prev->number)
		{
			prev = prev->next;
			nex = prev->next;
		}
		else
			return ;
	}
	exit (0);
}
