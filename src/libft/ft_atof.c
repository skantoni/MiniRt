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

int	valid_sign(char nptr, int *i)
{
	if (nptr == '-' || nptr == '+')
	{
		if (nptr == '-')
		{
			(*i)++;
			return (-1);
		}
		(*i)++;
	}
	return (1);
}

void	decima_cal(int *point, double *resp, char *nptr)
{
	static double	peso;

	peso = 0.1;
	if (*point == 1)
	{
		*resp = *resp + (*nptr - 48) * peso;
		peso = peso / 10.0;
	}
	else
		*resp = *resp * 10 + (*nptr - 48);
}

void	check_dot(char nptr, int *i, int *point)
{
	if (nptr == '.')
	{
		*point = 1;
		(*i)++;
	}
}

double	ft_atof(char *nptr)
{
	double	resp;
	int		sinal;
	int		i;
	int		point;

	resp = 0.0;
	sinal = 1;
	i = 0;
	point = 0;
	while ((nptr[i] == ' ' || nptr[i] == '\t'))
		i++;
	sinal = valid_sign(nptr[i], &i);
	if (!ft_isdigit(nptr[i]))
		return (resp);
	while (nptr[i])
	{
		check_dot(nptr[i], &i, &point);
		if (ft_isdigit(nptr[i]))
			decima_cal(&point, &resp, &nptr[i]);
		else
			return (sinal * resp);
		i++;
	}
	return (sinal * resp);
}
