/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 01:13:27 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/18 03:24:12 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	i = 0;
	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((pt1[i] != pt2[i]) || pt1[i] == '\0')
			return (pt1[i] - pt2[i]);
		i++;
	}
	return (0);
}
