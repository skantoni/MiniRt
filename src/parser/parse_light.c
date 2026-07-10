/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:38:29 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/10 19:45:03 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_position(char *token, t_scene *scene)
{
	char	**sub_tokens;

	sub_tokens = ft_split(token, ',');
	if (!sub_tokens)
		return (1);
	if (count_tokens(sub_tokens) != 3)
	{
		free_str_array(sub_tokens);
		return (print_error("Error:", "Invalid pos. tokens", NULL), 1);
	}
	scene->light.position.x = ft_atof(sub_tokens[0]);
	scene->light.position.y = ft_atof(sub_tokens[1]);
	scene->light.position.z = ft_atof(sub_tokens[2]);
	free_str_array(sub_tokens);
	return (0);
}

static int	parse_color_light(char *tokens, t_scene *scene)
{
	long	r;
	long	g;
	long	b;
	char	**sub_tokens;

	sub_tokens = ft_split(tokens, ',');
	if (!sub_tokens)
		return (1);
	if (count_tokens(sub_tokens) != 3)
	{
		free_str_array(sub_tokens);
		return (print_error("Error:", "Invalid col. tokens", NULL), 1);
	}
	r = ft_atol(sub_tokens[0]);
	g = ft_atol(sub_tokens[1]);
	b = ft_atol(sub_tokens[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (free_str_array(sub_tokens), 1);
	scene->light.color.r = (int)r;
	scene->light.color.g = (int)g;
	scene->light.color.b = (int)b;
	free_str_array(sub_tokens);
	return (0);
}

int	parse_light(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (count_tokens(tokens) != 4)
	{
		free_str_array(tokens);
		return (print_error("Error: ", "Invalid light tokens", NULL), 1);
	}
	if (parse_position(tokens[1], scene)
		|| parse_color_light(tokens[3], scene))
		return (free_str_array(tokens), 1);
	scene->light.brightness = ft_atof(tokens[2]);
	if (scene->light.brightness < 0.0
		|| scene->light.brightness > 1.0)
	{
		free_str_array(tokens);
		return (print_error("Error: ", "Out of range [0.0, 1.0]", NULL), 1);
	}
	free_str_array(tokens);
	return (0);
}
