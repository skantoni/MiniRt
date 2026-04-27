/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:01:04 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/28 11:02:26 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	inicio;
	size_t	fim;
	size_t	i;

	inicio = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[inicio] != '\0' && ft_strchr(set, s1[inicio]))
		inicio++;
	fim = ft_strlen(s1);
	while (fim > inicio && ft_strchr(set, s1[fim - 1]))
		fim--;
	str = (char *)malloc(sizeof(*s1) * (fim - inicio) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (inicio < fim)
	{
		str[i] = s1[inicio];
		i++;
		inicio++;
	}
	str[i] = '\0';
	return (str);
}
