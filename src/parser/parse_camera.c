/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:54:46 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/07 14:51:25 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_position(char *position, t_camera *cam)
{
    char    **sub_tokens_pos;

    sub_tokens_pos = ft_split(position, ',');
    if (!sub_tokens_pos)
        return (1);
    if (count_tokens(sub_tokens_pos) != 3)
        return (print_error("Error: ", "Wrong sub-tokens to positon", NULL), 1);
    cam->position.x = atof(sub_tokens_pos[0]);
    cam->position.y = atof(sub_tokens_pos[1]);
    cam->position.z = atof(sub_tokens_pos[2]);
    return (0);
}

int parse_orientation(char *orientation)
{
     char    **sub_tokens_ori;

    sub_tokens_ori = ft_split(orientation, ',');
    if (!sub_tokens_ori)
        return (1);
    if (count_tokens(sub_tokens_ori) != 3)
        return (print_error("Error: ", "Wrong sub-tokens to orientation", NULL), 1);
    return (0);
}

int parse_camera(char *line, t_camera *cam)
{
    char    **tokens;

    tokens = ft_split(line, ' ');
    if (!tokens)
        return (1);
    if (count_tokens(tokens) != 4)
        return (print_error("Error: ", "is missing tokens, check the in line camera", NULL), 1);
    parse_position(tokens[1], cam);
    return (0);
}
