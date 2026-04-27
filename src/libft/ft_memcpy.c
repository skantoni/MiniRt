/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:54:12 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/12 16:58:39 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*orgm;
	unsigned char	*destino;
	size_t			c;
	long			len;

	if ((!dest || !src) && n > 0)
		return (NULL);
	len = (long)n;
	if (len < 0)
		return (NULL);
	destino = (unsigned char *)dest;
	orgm = (unsigned char *)src;
	c = 0;
	while (c < n)
	{
		destino[c] = orgm[c];
		c++;
	}
	return (dest);
}
