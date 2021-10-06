/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_validate_and_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:31:02 by jmaryett          #+#    #+#             */
/*   Updated: 2021/10/06 19:21:08 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array_of_strings(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free (t[i]);
		i++;
	}
	free(t);
}

//проверяем символы на числа

int	is_digit_c(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

//сначала проверяем на минус в начале строки (если между символов,
//то невалидно); потом проверяем символы на числа

static int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (!is_digit_c(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	validate_arguments(char **arguments)
{
	int		i;

	i = 0;
	while (arguments[i] != NULL)
	{
		if (is_str_digit(arguments[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

//отсортированные сплитом арг делаем числом через атои и
//проверяем на мин и макс инт
//затем создаем элемент списка с числом и прикрепляем его к стеку

int	add_arguments_to_stack(t_stack **data_stack, char **arguments)
{
	int		i;
	long	number;
	t_stack	*tmp;

	i = 0;
	while (arguments[i] != NULL)
	{
		number = ft_atoi(arguments[i]);
		if (number < INT_MIN || INT_MAX < number)
			return (0);
		tmp = get_lst_new_elem((int)number);
		if (!tmp)
			return (0);
		lstadd_back(data_stack, tmp);
		i++;
	}
	return (1);
}
