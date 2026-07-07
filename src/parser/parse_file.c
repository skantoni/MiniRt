/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:35:24 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/07 14:30:55 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ratio(char **tokens, int len, t_scene *scene)
{
	int	i;
	int	ponto;

	i = 0;
	ponto = 0;
	if (len != 3)
		return (1);
	if (tokens[1][0] > '9' || tokens[1][0] < '0')
		return (1);
	while (tokens[1][i])
	{
		if (tokens[1][i] == '.')
			ponto++;
		else if ((tokens[1][i] < '0' || tokens[1][i] > '9'))
			return (1);
		i++;
	}
	scene->ambient.ratio = atof(tokens[1]);
	if ((scene->ambient.ratio < 0 || scene->ambient.ratio > 1) || ponto > 1)
		return (1);
	return (0);
}

int	parse_colors(char **tokens, int len, t_scene *scene)
{
	int	i;

	i = 0;
	if (len != 3)
		return (1);
	while (tokens[2][i])
	{
		if (tokens[2][0] > '9' || tokens[2][0] < '0')
		{
			print_error("Error: ", "Formato de cor inválido;", NULL);
			return (1);
		}
		if (tokens[2][i] != ',' && (tokens[2][i] < '0' || tokens[2][i] > '9'))
		{
			print_error("Error: ", "Formato de cor inválido;", NULL);
			return (1);
		}
		i++;
	}
	scene->ambient.color.r = ft_atoi((ft_split(tokens[2], ','))[0]);
	scene->ambient.color.g = ft_atoi((ft_split(tokens[2], ','))[1]);
	scene->ambient.color.b = ft_atoi((ft_split(tokens[2], ','))[2]);
	return (0);
}

int	parse_ambient(char *line, t_scene *scene)
{
	char	**tokens;
	int		i;
	int		tokens_len;

	tokens = ft_split(line, ' ');
	i = 0;
	if (scene->has_ambient)
	{
		free_str_array(tokens);
		print_error("Error", "Luz ambiente duplicada!", NULL);
		return (1);
	}
	tokens_len = count_tokens(tokens);
	printf("Tokens len -> %d\n", tokens_len);
	if (parse_ratio(tokens, tokens_len, scene)
		|| parse_colors(tokens, tokens_len, scene))
	{
		print_error("Error: ", "Formato de luz ambiente inválido;", NULL);
		free_str_array(tokens);
		return (1);
	}
	free_str_array(tokens);
	scene->has_ambient = 1;
	return (0);
}
