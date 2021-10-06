/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_0_small_ind_calculate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:58 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 20:12:44 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate moves to put elem to the top of 
//st b and the same for stack a after push it there
//we do this for each element in stack
// b and choose the one with least moves and move it to a

void	even_init_mv_in_b(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	if (len == 2)
	{
		tmp->moves = 1;
		tmp->next->moves = 2;
		return ;
	}
	while (i <= len / 2)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i++;
	}
	while (i >= 2 && tmp)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i--;
	}
}

void	even_init_mv_in_a(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = (*st)->next;
	while (i < len / 2)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i++;
	}
	while (i >= 1 && tmp)
	{
		tmp->moves = i;
		tmp = tmp->next;
		i--;
	}
}

void	init_mv_in_b(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = *st;
	if (len % 2 == 0)
		even_init_mv_in_b(st);
	else
	{
		while (i <= (len / 2) + 1)
		{
			tmp->moves = i;
			tmp = tmp->next;
			i++;
		}
		while (i >= 2 && tmp)
		{
			i--;
			tmp->moves = i;
			tmp = tmp->next;
		}
	}
}

void	init_mv_in_a(t_stack **st)
{
	int		len;
	int		i;
	t_stack	*tmp;

	i = 1;
	len = lstsize(*st);
	tmp = (*st)->next;
	if (len % 2 == 0)
		even_init_mv_in_a(st);
	else
	{
		while (i <= len / 2)
		{
			tmp->moves = i;
			tmp = tmp->next;
			i++;
		}
		while (i > 1 && tmp)
		{
			i--;
			tmp->moves = i;
			tmp = tmp->next;
		}
	}
}
