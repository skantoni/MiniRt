/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:36:25 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/13 09:36:26 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	is_valid_double(char *str)
{
	int	has_digit;
	int	has_dot;

	has_digit = 0;
	has_dot = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = 1;
		else if (*str == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else
			return (0);
		str++;
	}
	return (has_digit);
}

int	parse_vec3(char *str, t_vec3 *vec)
{
	char	**sub_tokens;

	sub_tokens = ft_split(str, ',');
	if (!sub_tokens)
		return (1);
	if (count_tokens(sub_tokens) != 3)
		return (free_str_array(sub_tokens), 1);
	if (!is_valid_double(sub_tokens[0])
		|| !is_valid_double(sub_tokens[1])
		|| !is_valid_double(sub_tokens[2]))
		return (free_str_array(sub_tokens), 1);
	vec->x = ft_atof(sub_tokens[0]);
	vec->y = ft_atof(sub_tokens[1]);
	vec->z = ft_atof(sub_tokens[2]);
	free_str_array(sub_tokens);
	return (0);
}
