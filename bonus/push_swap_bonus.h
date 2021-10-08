/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:28:19 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/08 11:30:35 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"

void	add_check_commands(char *line, t_stack **a, t_stack **b);
void	check_stacks(t_stack **a, t_stack **b);
t_stack	*parse_validate_input(int ac, char **av);
int		is_sorted(t_stack *stack);
void	write_msg_free_memory_and_exit(char *msg, t_stack *mem, int exit_code);

#endif