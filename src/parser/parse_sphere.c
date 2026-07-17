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

int	parse_sphere_color(char *color_str, t_sphere *sphere)
{
	char	**sub_tokens;
	int		values[3];
	int		i;

	sub_tokens = ft_split(color_str, ',');
	if (!sub_tokens || count_tokens(sub_tokens) != 3)
		return (printf("Error\nInvalid sphere color tokens\n"),
			free_str_array(sub_tokens), 1);
	i = 0;
	while (i < 3)
	{
		if (!is_valid_color_token(sub_tokens[i]))
		{
			printf("Error\nInvalid color token");
			return (free_str_array(sub_tokens), 1);
		}
		values[i] = ft_atoi(sub_tokens[i]);
		if (values[i] < 0 || values[i] > 255)
			return (free_str_array(sub_tokens), 1);
		i++;
	}
	sphere->color.r = values[0];
	sphere->color.g = values[1];
	sphere->color.b = values[2];
	return (free_str_array(sub_tokens), 0);
}

int	parse_sphere(char *line, t_scene *scene)
{
	char		**tokens;
	t_sphere	*new_sphere;

	tokens = ft_split(line, ' ');
	if (!tokens || count_tokens(tokens) != 4)
		return (printf("Error\nInvalid sphere tokens\n"),
			free_str_array(tokens), 1);
	new_sphere = malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (free_str_array(tokens), 1);
	new_sphere->next = NULL;
	if (parse_vec3(tokens[1], &new_sphere->center)
		|| parse_sphere_color(tokens[3], new_sphere))
		return (free(new_sphere), free_str_array(tokens), 1);
	new_sphere->diameter = ft_atof(tokens[2]);
	if (new_sphere->diameter <= 0)
		return (printf("Error\nInvalid sphere diameter\n"),
			free(new_sphere), free_str_array(tokens), 1);
	new_sphere->next = scene->spheres;
	scene->spheres = new_sphere;
	printf("SPHERE: center(%.2f, %.2f, %.2f), diameter(%.2f), color(%d, %d, %d)\n",
		new_sphere->center.x, new_sphere->center.y, new_sphere->center.z,
		new_sphere->diameter, new_sphere->color.r, new_sphere->color.g,
		new_sphere->color.b);
	return (free_str_array(tokens), 0);
}
