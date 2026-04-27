/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 07:19:34 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/20 13:42:42 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_ln;
	size_t	org_ln;
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	dest_ln = ft_strlen(dst);
	org_ln = ft_strlen(src);
	if (size <= dest_ln)
		return (size + org_ln);
	while ((i < size - dest_ln - 1) && (src[i] != '\0'))
	{
		dst[dest_ln + i] = src[i];
		i++;
	}
	if (dest_ln + i < size)
		dst[dest_ln + i] = '\0';
	return (dest_ln + org_ln);
}
