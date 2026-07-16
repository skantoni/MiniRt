/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:54:46 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/10 15:55:10 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_range(t_camera *cam)
{
	if (cam->orientation.x < -1.0f || cam->orientation.x > 1.0f)
		return (printf("Error\nCamera Ori x out of range [-1,1]"), 1);
	if (cam->orientation.y < -1.0f || cam->orientation.y > 1.0f)
		return (printf("Error\nCamera Ori y out of range [-1,1]"), 1);
	if (cam->orientation.z < -1.0f || cam->orientation.z > 1.0f)
		return (printf("Error\nCamera Ori z out of range [-1,1]"), 1);
	if (cam->fov < 0.0f || cam->fov > 180.0f)
		return (printf("Error\nCamera FOV out of range [0,180]"), 1);
	return (0);
}

int	parse_position(char *position, t_camera *cam)
{
	char	**sub_tokens_pos;

	sub_tokens_pos = ft_split(position, ',');
	if (!sub_tokens_pos)
		return (1);
	if (count_tokens(sub_tokens_pos) != 3)
	{
		free_str_array(sub_tokens_pos);
		return (printf("Error\nWrong sub-tokens to position"), 1);
	}
	cam->position.x = ft_atof(sub_tokens_pos[0]);
	cam->position.y = ft_atof(sub_tokens_pos[1]);
	cam->position.z = ft_atof(sub_tokens_pos[2]);
	free_str_array(sub_tokens_pos);
	return (0);
}

int	parse_camera(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (scene->has_camera)
	{
		free_str_array(tokens);
		return (printf("Error\nCamera duplicada!"), 1);
	}
	if (count_tokens(tokens) != 4)
	{
		free_str_array(tokens);
		return (printf("Error\nmust have 4 tokens camera"), 1);
	}
	if (parse_vec3(tokens[1], &scene->camera.position)
		|| parse_vec3(tokens[2], &scene->camera.orientation))
		return (free_str_array(tokens), 1);
	scene->camera.fov = ft_atof(tokens[3]);
	free_str_array(tokens);
	if (validate_range(&scene->camera))
		return (1);
	scene->has_camera = 1;
	return (0);
}
