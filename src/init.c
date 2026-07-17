/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:44:22 by pavelino          #+#    #+#             */
/*   Updated: 2026/06/09 15:24:52 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void    init(t_scene *scene, t_mlx *mlx)
{
    ft_memset(scene, 0, sizeof(t_scene));
    ft_memset(mlx, 0, sizeof(t_mlx));
}