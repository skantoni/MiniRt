/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:18:51 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/14 15:03:14 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int  parse_color_plane(char *token, t_plane *plane)
{
    char    **sub_token;
    long    r;
    long    g;
    long    b;

    if (check_del(token, ',', 2))
        return (printf("Error\ninvalid format color"), 1);
    sub_token = ft_split(token, ',');
    if (!sub_token || count_tokens(sub_token) != 3)
        return (printf("Error\nInvalid token"), 1);
    r = ft_atol(sub_token[0]);
    g = ft_atol(sub_token[1]);
    b = ft_atol(sub_token[2]);
    if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0 ))
        return (free_str_array(sub_token), 1);
    plane->color.r = (int)r;
    plane->color.g = (int)g;
    plane->color.b = (int)b;
    return (free_str_array(sub_token), 0);
}

int parse_plane(char *line, t_scene *scene)
{
    char **tokens;
    t_plane *new_plane;

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
