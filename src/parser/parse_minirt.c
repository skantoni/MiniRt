/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:12:00 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/14 15:03:36 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_line(char *line, t_scene *scene)
{
	int		sign;

	sign = 1;
	if (ft_strncmp(line, "A ", 2) == 0)
		sign = parse_ambient(line, scene);
	else if (ft_strncmp(line, "C ", 2) == 0)
		sign = parse_camera(line, scene);
	else if (ft_strncmp(line, "L ", 2) == 0)
		sign = parse_light(line, scene);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		sign = parse_sphere(line, scene);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		sign = parse_cylinder(line, scene);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		sign = parse_plane(line, scene);
	else
	{
		printf("Error\nUnknown identifier: %s", line);
		sign = 1;
	}
	return (sign);
}

int	parse_extention(char *av)
{
	char	*str;

	str = ft_strrchr(av, '.');
	if (ft_strncmp(".rt", str, 4) == 0)
		return (0);
	printf("Error\nInvalid file extension");
	return (1);
}

static int	parse_file(char *av, t_scene *scene)
{
	int	i;

	if (read_file(av, scene))
		return (1);
	i = 0;
	while (scene->file[i])
	{
		if (parse_line(scene->file[i++], scene))
			return (/*print_error("Error", "Unknown identifier", NULL),*/ 1);
	}
	return (0);
}

int	parse_minirt(char *av, t_scene *scene)
{
	if (parse_extention(av))
		return (1);
	if (parse_file(av, scene))
		return (1);
	return (0);
}
