/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:48:40 by skantoni          #+#    #+#             */
/*   Updated: 2026/06/09 15:34:53 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_window(t_mlx *mlx)
{
    if (mlx->win)
	    mlx_destroy_window(mlx->mlx, mlx->win);
    if (mlx->mlx)
    {
        mlx_destroy_display(mlx->mlx);
	    exit(0);
    }
	return (0);
}

int handle_escape(int keycode, t_mlx *mlx)
{
    if (keycode ==  65307)
        close_window(mlx);
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
        scene->file = NULL;
    }
	if (mlx)
    {
        close_window(mlx);
    }
	return(status);
}
