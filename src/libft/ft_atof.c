/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:04:46 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/10 17:10:58 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_decimal(char **str)
{
	double	res;
	double	divisor;

	res = 0.0;
	divisor = 10.0;
	if (**str == '.')
		(*str)++;
	while (ft_isdigit(**str))
	{
		res += (**str - '0') / divisor;
		divisor *= 10.0;
		(*str)++;
	}
	return (res);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;

	res = 0.0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res += parse_decimal(&str);
	return (res * sign);
}
