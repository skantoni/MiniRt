/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:18:49 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/18 19:31:36 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		c = 0;
		while (big[i + c] == little[c] && (i + c) < len)
		{
			if (little[c + 1] == '\0')
			{
				return ((char *)(big + i));
			}
			c++;
		}
		i++;
	}
	return (NULL);
}
