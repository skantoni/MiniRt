/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:12:00 by pavelino          #+#    #+#             */
/*   Updated: 2026/05/23 15:02:34 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int parse_line(char *line, t_scene *scene)
{

	(void)scene;
	if (ft_strncmp(line, "A ", 2) == 0)
		return (printf("Ambient\n"), 0);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (printf("CAMERA\n"), 0);
	else if (ft_strncmp(line, "L ", 2) == 0)
		return (printf("LIGHT\n"), 0);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		return (printf("SPHERE\n"),0);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		return (printf("CYLINDER\n"), 0);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		return (printf("PLANE\n"), 0);

/* 	if (ft_strncmp(line, "A ", 2) == 0)
		parse_ambient(line, scene);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_camera(line, scene);
	else if (ft_strncmp(line, "L ", 2) == 0)
		parse_light(line, scene);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		parse_sphere(line, scene); */
	return (1);
}

int	parse_extention(char *av)
{
	char	*str;

	str = ft_strrchr(av, '.');
	if (ft_strncmp(".rt", str, 4) == 0)
		return (0);
	print_error("minirt", "Verifique a extensao do arquivo", NULL);
	return (1);
}

static int	parse_file(char *av, t_scene *scene)
{
	int	i;

	if (read_file(av, scene))
	{
		//Nao preciso liberar nada
		return (1);
	}
	i = 0;
	while (scene->file[i])
		if (parse_line(scene->file[i++], scene))
			return (printf("minirt: Invalid identifier %s", scene->file[--i]), free(scene->file[i]), 1);
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
