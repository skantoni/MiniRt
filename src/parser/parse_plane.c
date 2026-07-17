/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:18:51 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/17 12:40:34 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_color_plane(char *token, t_plane *plane)
{
	char	**sub_token;
    int i;
	long	rgb[3];

	if (check_del(token, ',', 2))
		return (printf("Error\ninvalid format color"), 1);
	sub_token = ft_split(token, ',');
	if (!sub_token || count_tokens(sub_token) != 3)
		return (printf("Error\nInvalid token"), 1);
	i = 0;
    while (i < 3)
    {
        rgb[i] = ft_atol(sub_token[i]);
        i++;
    }
	if (check_color_range(rgb[0], rgb[1], rgb[2]))
		return (free_str_array(sub_token), 1);
	plane->color.r = (int)rgb[0];
	plane->color.g = (int)rgb[1];
	plane->color.b = (int)rgb[2];
	return (free_str_array(sub_token), 0);
}

int	parse_plane(char *line, t_scene *scene)
{
	char	**tokens;
	t_plane	*new_plane;

	tokens = ft_split(line, ' ');
	if (!tokens || count_tokens(tokens) != 4)
	{
		free_str_array(tokens);
		return (printf("Error\nInvalid tokens to plane"), 1);
	}
	new_plane = malloc(sizeof(t_plane));
	if (!new_plane)
		return (free_str_array(tokens), 1);
	new_plane->next = NULL;
	if (parse_vec3(tokens[1], &new_plane->point)
		|| parse_vec3(tokens[2], &new_plane->normal)
		|| parse_color_plane(tokens[3], new_plane))
		return (free_str_array(tokens), 1);
	new_plane->normal = vec3_normalize(new_plane->normal);
	new_plane->next = scene->planes;
	scene->planes = new_plane;
	return (free_str_array(tokens), 0);
}
