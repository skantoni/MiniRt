/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:54:46 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/06 18:17:48 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int count_tokens(char **tokens)
{
    int i;

    i = 0;
    while(tokens[i])
        i++;
    return (i);
}


int parse_camera(char *line)
{
    char    **tokens;
    char    *newLine;

    newLine = ft_strtrim (line, " ");
    if (!newLine)
        return (1);
    tokens = ft_split(newLine, ' ');
    if (!tokens)
        return (1);
    if (count_tokens(tokens) != 4)
    {
        free_str_array(tokens);
        return (print_error("Error: ", "is missing tokens, check the in line camera", NULL), 1);
    }
    free_str_array(tokens);
    return (0);
}
