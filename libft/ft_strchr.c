/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:52:05 by chudapak          #+#    #+#             */
/*   Updated: 2021/10/11 18:52:05 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if ((char)ch == '\0')
	{
		while (*str)
		{
			if (*str == '\0')
				return ((char *)str);
			str++;
		}
		return ((char *)str);
	}
	if (*str == '\0')
		return (NULL);
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
