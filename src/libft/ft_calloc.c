/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:43:01 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/20 17:27:49 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*vetor;
	size_t	qb;

	qb = nmemb * size;
	if (size && (qb / size) != nmemb)
		return (NULL);
	vetor = malloc(qb);
	if (vetor == NULL)
		return (NULL);
	ft_bzero(vetor, qb);
	return (vetor);
}
