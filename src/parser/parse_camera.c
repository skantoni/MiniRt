/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:54:46 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/09 19:51:02 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_range(t_camera *cam)
{
	if (cam->orientation.x < -1.0f || cam->orientation.x > 1.0f)
		return (print_error("Error:", "Ori x out of range [-1,1]", NULL), 1);
	if (cam->orientation.y < -1.0f || cam->orientation.y > 1.0f)
		return (print_error("Error:", "Ori y out of range [-1,1]", NULL), 1);
	if (cam->orientation.z < -1.0f || cam->orientation.z > 1.0f)
		return (print_error("Error: ", "Ori z out of range [-1,1] ", NULL), 1);
	if (cam->fov < 0.0f || cam->fov > 180.0f)
		return (print_error("Error: ", "FOV out of range [0,180] ", NULL), 1);
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
		return (print_error("Error:", "Wrong sub-tokens to posi.", NULL), 1);
	}
	cam->position.x = atof(sub_tokens_pos[0]);
	cam->position.y = atof(sub_tokens_pos[1]);
	cam->position.z = atof(sub_tokens_pos[2]);
	free_str_array(sub_tokens_pos);
	return (0);
}

int	parse_orientation(char *orientation, t_camera *cam)
{
	char	**sub_tokens_ori;

	sub_tokens_ori = ft_split(orientation, ',');
	if (!sub_tokens_ori)
		return (1);
	if (count_tokens(sub_tokens_ori) != 3)
	{
		free_str_array(sub_tokens_ori);
		return (print_error("Error: ", "Wrong sub-tokens to ori.", NULL), 1);
	}
	cam->orientation.x = atof(sub_tokens_ori[0]);
	cam->orientation.y = atof(sub_tokens_ori[1]);
	cam->orientation.z = atof(sub_tokens_ori[2]);
	free_str_array(sub_tokens_ori);
	return (0);
}

int	parse_camera(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (count_tokens(tokens) != 4)
	{
		free_str_array(tokens);
		return (print_error("Error:", "must have 4 tokens camera", NULL), 1);
	}
	if (parse_position(tokens[1], &scene->camera)
		|| parse_orientation(tokens[2], &scene->camera))
		return (free_str_array(tokens), 1);
	scene->camera.fov = atof(tokens[3]);
	free_str_array(tokens);
	if (validate_range(&scene->camera))
		return (1);
	return (0);
}
