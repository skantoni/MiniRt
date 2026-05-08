/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:31:30 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/21 15:13:03 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*veri_substr(char const *str, unsigned int i, size_t tama)
{
	size_t	j;
	char	*substr;

	substr = malloc(tama + 1);
	if (!substr)
		return (NULL);
	j = 0;
	while (j < tama && str[i] != '\0')
	{
		substr[j] = str[i];
		j++;
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	tamatotal;
	long	neg;

	if (!s)
		return (NULL);
	neg = (long)len;
	if (neg < 0)
		return (NULL);
	tamatotal = ft_strlen(s);
	if (start >= tamatotal)
		return (ft_strdup(""));
	if (len > tamatotal - start)
		len = tamatotal - start;
	return (veri_substr(s, start, len));
}
