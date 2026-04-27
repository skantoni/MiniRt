/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:37:37 by pavelino          #+#    #+#             */
/*   Updated: 2026/04/27 13:32:36 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int ac, char **av)
{
	t_mlx	*wind;

	if (ac < 2)
		return (1);
	wind = malloc(sizeof(t_mlx));
	if (!wind)
		return (1);
	wind->wdh = ft_atoi(av[1]);
	wind->hgt = ft_atoi(av[2]);
	wind->mlx = mlx_init();
	wind->win = mlx_new_window(wind->mlx, wind->wdh, wind->hgt, "Minirt");
	mlx_loop(wind->mlx);	
	return (0);
}
