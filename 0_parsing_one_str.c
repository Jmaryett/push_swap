/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parsing_one_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:31:02 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/30 21:02:02 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing_one_str(char *av)
{
	int		i;
	char	**array;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			error_case("Error\nInvalid str.\n");
		i++;
	}
	array = ft_split(av, ' ');
	return (array);
}
