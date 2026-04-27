/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:17:55 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/16 13:59:34 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	tama;

	if (!dst || !src)
		return (0);
	tama = ft_strlen(src);
	c = 0;
	if (size > 0)
	{
		while ((c < size - 1) && (src[c] != '\0'))
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (tama);
}
