/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:52:21 by chudapak          #+#    #+#             */
/*   Updated: 2021/10/11 18:52:21 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		n;

	i = 0;
	if (!dst || !src)
		return (0);
	if (len > 0)
	{
		while (src[i] && --len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	n = ft_strlen(src);
	return (n);
}
