/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:51 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:47:52 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
