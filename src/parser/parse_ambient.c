/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:01:30 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/13 09:01:32 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ratio(char **tokens, int len, t_scene *scene)
{
	int	i;
	int	delimiter_count;

	i = 0;
	delimiter_count = 0;
	if (len != 3)
		return (1);
	if (tokens[1][0] > '9' || tokens[1][0] < '0')
		return (1);
	while (tokens[1][i])
	{
		if (tokens[1][i] == '.')
			delimiter_count++;
		else if ((tokens[1][i] < '0' || tokens[1][i] > '9'))
			return (1);
		i++;
	}
	scene->ambient.ratio = ft_atof(tokens[1]);
	if ((scene->ambient.ratio < 0
			|| scene->ambient.ratio > 1) || delimiter_count > 1)
		return (1);
	return (0);
}

int	parse_tokens(char **tokens, t_scene *scene)
{
	long	r;
	long	g;
	long	b;
	char	**sub_tokens;

	sub_tokens = ft_split(tokens[2], ',');
	if (!sub_tokens)
		return (1);
	r = ft_atol(sub_tokens[0]);
	g = ft_atol(sub_tokens[1]);
	b = ft_atol(sub_tokens[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
	{
		free_str_array(sub_tokens);
		return (1);
	}
	scene->ambient.color.r = (int)r;
	scene->ambient.color.g = (int)g;
	scene->ambient.color.b = (int)b;
	free_str_array(sub_tokens);
	return (0);
}

int	parse_colors(char **tokens, int len, t_scene *scene)
{
	int	i;
	int	delimiter_count;

	i = 0;
	delimiter_count = 0;
	if (len != 3)
		return (1);
	while (tokens[2][i])
	{
		if (tokens[2][i] == ',')
			delimiter_count++;
		if (tokens[2][0] > '9' || tokens[2][0] < '0')
			return (1);
		if (tokens[2][i] != ',' && (tokens[2][i] < '0' || tokens[2][i] > '9'))
			return (1);
		i++;
	}
	if (delimiter_count != 2 || parse_tokens(tokens, scene))
		return (1);
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
