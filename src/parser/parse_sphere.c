/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:10:47 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/14 14:00:00 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sphere_color(char *color_str, t_sphere *sphere)
{
	char	**sub_tokens;

	sub_tokens = ft_split(color_str, ',');
	if (!sub_tokens || count_tokens(sub_tokens) != 3)
		return (free_str_array(sub_tokens), 1);
	sphere->color.r = ft_atoi(sub_tokens[0]);
	sphere->color.g = ft_atoi(sub_tokens[1]);
	sphere->color.b = ft_atoi(sub_tokens[2]);
	return (free_str_array(sub_tokens), 0);
}

int	parse_sphere(char *line, t_scene *scene)
{
	char		**tokens;
	t_sphere	*new_sphere;

	tokens = ft_split(line, ' ');
	if (!tokens || count_tokens(tokens) != 4)
		return (free_str_array(tokens), 1);
	new_sphere = malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (free_str_array(tokens), 1);
	new_sphere->next = NULL;
	if (parse_vec3(tokens[1], &new_sphere->center)
		|| parse_sphere_color(tokens[3], new_sphere))
		return (free(new_sphere), free_str_array(tokens), 1);
	new_sphere->diameter = ft_atof(tokens[2]);
	new_sphere->next = scene->spheres;
	scene->spheres = new_sphere;
	return (free_str_array(tokens), 0);
}
