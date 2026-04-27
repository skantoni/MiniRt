/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:02:08 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/12 19:22:29 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptdest;
	unsigned char	*ptorgm;
	long			len;

	if ((!dest || !src) && (n > 0))
		return (NULL);
	len = (long)n;
	if (len < 0)
		return (NULL);
	ptdest = (unsigned char *)dest;
	ptorgm = (unsigned char *)src;
	if (ptdest < ptorgm)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		ptdest[n - 1] = ptorgm[n - 1];
		n--;
	}
	return (dest);
}
