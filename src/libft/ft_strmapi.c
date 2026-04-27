/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:51:17 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/23 13:18:27 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		tama;
	char		*nova_str;

	if (!s || !f)
		return (NULL);
	tama = ft_strlen(s);
	nova_str = (char *)malloc(sizeof (char) * (tama + 1));
	if (!nova_str)
		return (NULL);
	i = 0;
	while (i < tama)
	{
		nova_str[i] = f(i, s[i]);
		i++;
	}
	nova_str[i] = '\0';
	return (nova_str);
}
