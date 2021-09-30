/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:46:53 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 17:46:55 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_min_max_int(char **array)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (array[++i])
	{
		n = ft_atoi(array[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		n = 0;
	}
	return (1);
}

static int	check_dupl_atoi(char *s1, char *s2)
{
	int	n;
	int	n2;

	n = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if (n == n2)
		return (0);
	return (1);
}

static int	check_duplicates(char **array)
{
	int	i;
	int	prev;

	i = 1;
	prev = 2;
	while (array[i])
	{
		while (array[prev])
		{
			if (!check_dupl_atoi(array[i], array[prev]))
				return (0);
			prev++;
		}
		i++;
		prev = i + 1;
	}
	return (1);
}

static void	check_char_valid(char **array, int i, int c)
{
	int	j;

	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			while (array[i][j] == ' ')
				j++;
			while (array[i][j] == '-')
			{
				j++;
				c++;
			}
			if (((array[i][j] < '0' || array[i][j] > '9') &&
				 array[i][j] != '-') ||
				c > 1 || array[i][j + 1] == ' ')
				error_case("Error\nInvalid arguments.\n");
			j++;
		}
		c = 0;
		i++;
	}
	return ;
}

void	check_input(char **array)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (!array || !*array)
		return ;
	check_char_valid(array, i, count);
	if (!check_duplicates(array))
		error_case("Error\nFound duplicates.\n");
	else if (!check_min_max_int(array))
		error_case("Error\nValue is over MIN or MAX int.\n");
	return ;
}
