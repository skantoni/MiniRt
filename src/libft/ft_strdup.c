/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:03:19 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/20 17:49:26 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	tama;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	tama = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (tama + 1));
	if (!str)
		return (NULL);
	while (i < tama)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
