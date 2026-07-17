/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:38:55 by pavelino          #+#    #+#             */
/*   Updated: 2026/07/17 12:44:54 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_color_range(long r, long g, long b)
{
	return ((r >= 0 && r <= 255) && (g >= 0 && g <= 255)
		&& (b >= 0 && b <= 255));
}

int check_del(char *str, char del, int n)
{
    int i;
    int del_num;

    i = 0;
    del_num = 0;
    while (str[i])
    {
        if (str[i] == del)
            del_num++;
        i++;
    }
    if (del_num != n)
        return (1);
    return (0);
}

t_vec3 vec3_normalize(t_vec3 v)
{
    double magnitute;

    magnitute = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    if (magnitute == 0)
        return (v);
    return ((t_vec3){v.x / magnitute, v.y / magnitute, v.z / magnitute});
}