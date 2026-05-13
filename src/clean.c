/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:48:40 by skantoni          #+#    #+#             */
/*   Updated: 2026/05/11 13:48:42 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

int	close_window(t_mlx *mlx)
{
    if (mlx->win)
	    mlx_destroy_window(mlx->mlx, mlx->win);
    mlx_destroy_display(mlx->mlx);
	exit(0);
	return (0);
}

int	clean(t_mlx *mlx, t_scene *scene, int status)
{
	int	i;

    i = 0;
    if (scene->file)
    {
        while(scene->file[i])
        {
            free(scene->file[i]);
            i++;
        }
        free(scene->file);
    }
	i = 0;
    close_window(mlx);
	return(status);
}
