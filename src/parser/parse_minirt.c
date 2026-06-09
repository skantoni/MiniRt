/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:12:00 by pavelino          #+#    #+#             */
/*   Updated: 2026/06/09 15:57:35 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int parse_line(char *line, t_scene *scene)
{
	(void)scene;
	
	char	**tokens;

	tokens = tokenizer_info(line);
	if (!tokens)
		return(1);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
	{
		if (parse_ambient(tokens, scene))
		{
			free_split(tokens);
			exit(1);
		}
		free_split(tokens);
		return (0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (printf("CAMERA\n"), free_split(tokens),  0);
	else if (ft_strncmp(line, "L ", 2) == 0)
		return (printf("LIGHT\n"), free_split(tokens), 0);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		return (printf("SPHERE\n"), free_split(tokens), 0);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		return (printf("CYLINDER\n"), free_split(tokens), 0);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		return (printf("PLANE\n"),free_split(tokens), 0);
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
	print_error("Error", "Invalid file extension", NULL);
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
			return (print_error("Error", "Unknown identifier", NULL),
			printf("%s", scene->file[--i]), free(scene->file[i]), 1);
	if (!scene->has_ambient)
	{
		print_error("Erro", "Missing Light Ambient", NULL);
		
		return (1);
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
