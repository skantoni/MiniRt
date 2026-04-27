/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:14:16 by pavelino          #+#    #+#             */
/*   Updated: 2025/06/22 12:37:50 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conta_num(int num)
{
	int	tama;

	tama = 0;
	if (num <= 0)
		tama++;
	while (num != 0)
	{
		num = num / 10;
		tama++;
	}
	return (tama);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	num;	

	num = n;
	len = conta_num(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	else if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		len--;
		s[len] = '0' + (num % 10);
		num = num / 10;
	}
	return (s);
}
