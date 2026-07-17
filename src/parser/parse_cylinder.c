/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:43:54 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/17 12:43:01 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_cylinder_color(char *token, t_cylinder *cylinder)
{
	char	**sub_tokens;
	long	rgb[3];
	int		i;

	if (check_del(token, ',', 2))
		return (1);
	sub_tokens = ft_split(token, ',');
	if (!sub_tokens || count_tokens(sub_tokens) != 3)
		return (free_str_array(sub_tokens), 1);
	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(sub_tokens[i][0]))
			return (free_str_array(sub_tokens), 1);
		rgb[i] = ft_atol(sub_tokens[i]);
		i++;
	}
	if (!check_color_range(rgb[0], rgb[1], rgb[2]))
		return (free_str_array(sub_tokens), 1);
	cylinder->color.r = (int)rgb[0];
	cylinder->color.g = (int)rgb[1];
	cylinder->color.b = (int)rgb[2];
	return (free_str_array(sub_tokens), 0);
}

static int	validate_orientation(t_vec3 normal)
{
	if (normal.x < -1.0 || normal.x > 1.0)
		return (1);
	if (normal.y < -1.0 || normal.y > 1.0)
		return (1);
	if (normal.z < -1.0 || normal.z > 1.0)
		return (1);
	if (normal.x == 0.0 && normal.y == 0.0 && normal.z == 0.0)
		return (1);
	return (0);
}

static int	validate_dimensions(t_cylinder *cyl)
{
	if (cyl->diameter <= 0 || cyl->height <= 0)
		return (printf("Error\nInvalid cylinder dimensions"), 1);
	return (0);
}

int	parse_cylinder(char *line, t_scene *scene)
{
	char		**tokens;
	t_cylinder	*cyl;

	tokens = ft_split(line, ' ');
	if (!tokens || count_tokens(tokens) != 6)
		return (free_str_array(tokens), 1);
	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		return (free_str_array(tokens), 1);
	cyl->next = NULL;
	if (parse_vec3(tokens[1], &cyl->center)
		|| parse_vec3(tokens[2], &cyl->normal)
		|| validate_orientation(cyl->normal)
		|| parse_cylinder_color(tokens[5], cyl))
		return (free(cyl), free_str_array(tokens), 1);
	cyl->normal = vec3_normalize(cyl->normal);
	cyl->diameter = ft_atof(tokens[3]);
	cyl->height = ft_atof(tokens[4]);
	if (validate_dimensions(cyl))
		return (free(cyl), free_str_array(tokens), 1);
	cyl->next = scene->cylinders;
	scene->cylinders = cyl;
	printf("CYLINDER: center(%.2f, %.2f, %.2f), normal(%.2f, %.2f, %.2f), diameter(%.2f), height(%.2f), color(%d, %d, %d)\n",
		cyl->center.x, cyl->center.y, cyl->center.z,
		cyl->normal.x, cyl->normal.y, cyl->normal.z,
		cyl->diameter, cyl->height,
		cyl->color.r, cyl->color.g, cyl->color.b);
	return (free_str_array(tokens), 0);
}
