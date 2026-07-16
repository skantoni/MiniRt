/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:43:54 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/14 14:44:01 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_valid_color_token(char *token)
{
	int	idx;

	if (!token || !*token)
		return (0);
	idx = 0;
	while (token[idx])
	{
		if (!ft_isdigit(token[idx]))
			return (0);
		idx++;
	}
	return (1);
}

static int	parse_cylinder_color(char *token, t_cylinder *cylinder)
{
	char	**sub_tokens;
	long	r;
	long	g;
	long	b;

	if (check_del(token, ',', 2))
		return (1);
	sub_tokens = ft_split(token, ',');
	if (!sub_tokens || count_tokens(sub_tokens) != 3)
		return (free_str_array(sub_tokens), 1);
	if (!is_valid_color_token(sub_tokens[0])
		|| !is_valid_color_token(sub_tokens[1])
		|| !is_valid_color_token(sub_tokens[2]))
		return (free_str_array(sub_tokens), 1);
	r = ft_atol(sub_tokens[0]);
	g = ft_atol(sub_tokens[1]);
	b = ft_atol(sub_tokens[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (free_str_array(sub_tokens), 1);
	cylinder->color = ((int)r << 16) | ((int)g << 8) | (int)b;
	free_str_array(sub_tokens);
	return (0);
}

static int	validate_orientation(t_vec3 normal)
{
	if (normal.x < -1.0 || normal.x > 1.0)
		return (0);
	if (normal.y < -1.0 || normal.y > 1.0)
		return (0);
	if (normal.z < -1.0 || normal.z > 1.0)
		return (0);
	if (normal.x == 0.0 && normal.y == 0.0 && normal.z == 0.0)
		return (0);
	return (1);
}

int	parse_cylinder(char *line, t_scene *scene)
{
	char		**tokens;
	t_cylinder	*new_cylinder;

	tokens = ft_split(line, ' ');
	if (!tokens || count_tokens(tokens) != 6)
		return (free_str_array(tokens), 1);
	new_cylinder = malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		return (free_str_array(tokens), 1);
	new_cylinder->next = NULL;
	if (parse_vec3(tokens[1], &new_cylinder->center)
		|| parse_vec3(tokens[2], &new_cylinder->normal)
		|| !validate_orientation(new_cylinder->normal)
		|| parse_cylinder_color(tokens[5], new_cylinder))
		return (free(new_cylinder), free_str_array(tokens), 1);
	new_cylinder->normal = vec3_normalize(new_cylinder->normal);
	new_cylinder->diameter = ft_atof(tokens[3]);
	new_cylinder->height = ft_atof(tokens[4]);
	if (new_cylinder->diameter <= 0 || new_cylinder->height <= 0)
		return (free(new_cylinder), free_str_array(tokens), 1);
	new_cylinder->next = scene->cylinders;
	scene->cylinders = new_cylinder;
	printf("CYLINDER: center(%.2f, %.2f, %.2f), normal(%.2f, %.2f, %.2f), diameter(%.2f), height(%.2f), color(%.2f, %.2f, %.2f)\n",
		new_cylinder->center.x, new_cylinder->center.y, new_cylinder->center.z,
		new_cylinder->normal.x, new_cylinder->normal.y, new_cylinder->normal.z,
		new_cylinder->diameter, new_cylinder->height, 
		(float)((new_cylinder->color >> 16) & 0xFF) / 255.0,
		(float)((new_cylinder->color >> 8) & 0xFF) / 255.0,
		(float)(new_cylinder->color & 0xFF) / 255.0);
	free_str_array(tokens);
	return (0);
}
