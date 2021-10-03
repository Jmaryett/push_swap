/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_0_recalculate_moves_for_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:21:23 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/03 21:28:10 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	even_reinit_mv_in_a(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	while (i < len / 2)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i++;
	}
	while (i >= 0 && tmp)
	{
		i--;
		tmp->moves = i;
		tmp = tmp->next;
	}
}

void	reinit_mv_in_a(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	if (len % 2 == 0)
		even_reinit_mv_in_a(st);
	else
	{
		while (i <= len / 2)
		{
			tmp->moves = i;
			tmp = tmp->next;
			i++;
		}
		while (i > 0 && tmp)
		{
			tmp->moves = i;
			tmp = tmp->next;
			i--;
		}
	}
}