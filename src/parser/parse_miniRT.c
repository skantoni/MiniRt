/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_miniRT.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:12:00 by pavelino          #+#    #+#             */
/*   Updated: 2026/05/02 12:48:10 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int parse_extetion(char *arg)
{
    char    *str;

    str = ft_strrchr(arg, '.');
    if (ft_strncmp(".rt", str, 4) == 0)
        return (0);
    write(2, "Verifique a extensao do arquivo\n", 32);
    return (1);
}

