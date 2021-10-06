/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_1_small_ind_a_b_in_diff_halfs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:48:09 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 20:39:51 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_up_b_down_small(t_stack **a, t_stack **b, t_best *best)
{
	while (*a != best->tmp_a)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push_b_down(b);
	return ;
}

void	a_down_b_up_small(t_stack **a, t_stack **b, t_best *best)
{
	while (*a != best->tmp_a)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	push_b_up(b);
	return ;
}
