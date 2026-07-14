/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:18:51 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/14 12:28:36 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int parse_point(char *token, t_scene *scene)
{
    char **sub_tokens;
    
    if (check_del(token,',', 2))
        return (1);
    sub_tokens = ft_split(token, ',');
    if (!sub_tokens)
        return (1);
    if (count_tokens(sub_tokens) != 3)
    {
        free_str_array(sub_tokens);
        return(print_error("Error: ", "Invalid point arg.", NULL), 1);
    }
    scene->planes->point.x = ft_atof(sub_tokens[0]);
    scene->planes->point.y = ft_atof(sub_tokens[1]);
    scene->planes->point.z = ft_atof(sub_tokens[2]);
    free_str_array(sub_tokens);
    return (0);
}

static t_vec3 parse_plvec(char **sub_tokens, t_plane *plane)
{
    plane->normal.x = ft_atof(sub_tokens[0]);
    plane->normal.y = ft_atof(sub_tokens[1]);
    plane->normal.z = ft_atof(sub_tokens[2]);
    return (plane->normal);
}

static int parse_normal(char *token, t_scene *scene)
{
    char **sub_tokens;

    sub_tokens = ft_split(token, ',');
    if (!sub_tokens)
        return (1);
    if (count_tokens(sub_tokens) != 3)
    {
        free_str_array(sub_tokens);
        return(print_error("Error: ", "Invalid point arg.", NULL), 1);
    }
    scene->planes->normal = vec3_normalize(parse_plvec(sub_tokens, scene->planes));
    return (0);
}

int parse_plane(char *line, t_scene *scene)
{
    char **tokens;
    t_plane *new_plane;

    tokens = ft_split(line, ' ');
    if (!tokens)
        return (1);
    if (count_tokens(tokens) != 4)
    {
        free_str_array(tokens);
        return (print_error("Error: ", "Invalid tokens to plane", NULL), 1);
    }
    new_plane = malloc(sizeof(t_plane));
    if (!new_plane)
        return (free_str_array(tokens), 1);
    if (parse_point(tokens[1], scene) || parse_normal(tokens[2], scene))
        return (free_str_array(tokens), 1);
    free_str_array(tokens);
    return (0);
}