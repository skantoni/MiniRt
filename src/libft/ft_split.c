/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:59:37 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/25 15:13:19 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cont_p(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	conta_palavras(char const *s, char c)
{
	size_t	i;
	size_t	contador;

	i = 0;
	contador = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			contador++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (contador);
}

static char	**ft_free(char **s, size_t n)
{
	if (!s)
		return (NULL);
	while (n--)
		free(s[n]);
	free(s);
	return (NULL);
}

static char	**dividir(char **result, char const *s, char c)
{
	size_t	i;
	size_t	qtdp;

	i = 0;
	qtdp = conta_palavras(s, c);
	while (i < qtdp)
	{
		while (*s)
		{
			if (*s != c)
			{
				result[i] = (char *)malloc(sizeof(char) * (cont_p(s, c)) + 1);
				if (!result[i])
					return (ft_free(result, qtdp));
				ft_strlcpy(result[i], s, cont_p(s, c) + 1);
				s += cont_p(s, c);
				i++;
			}
			else
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	qnt_p;

	if (!s)
		return (NULL);
	qnt_p = conta_palavras(s, c);
	result = (char **)malloc(sizeof(char *) * (qnt_p + 1));
	if (!result)
		return (NULL);
	return (dividir(result, s, c));
}
