/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:16:27 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/11 17:45:23 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pont;
	size_t			i;

	if (!s)
		return ;
	pont = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		pont[i] = 0;
		i++;
	}
}
