/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 02:37:13 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/18 03:24:49 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	long				len;
	const unsigned char	*ptr;

	if (!s)
		return (NULL);
	len = (long)n;
	if (len < 0)
		return (NULL);
	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
