/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_list_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:47:18 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:47:19 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *begin)
{
	int		len;
	t_stack	*tmp;

	if (!begin)
		return (0);
	tmp = begin;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
