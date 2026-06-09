/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:37:37 by pavelino          #+#    #+#             */
/*   Updated: 2026/06/02 18:46:10 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (0);
	return (0);
} */

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;
	t_scene scene;

	if (ac != 2 || av[1][0] == '\0')
		return (print_error("minirt", "Insira", "./miniRT scene.rt"), 1);
	init(&scene);
	if (parse_minirt(av[1], &scene))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\n", 6), 1);
	create_window(&mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, handle_escape, &mlx);
	mlx_loop(mlx.mlx);
	clean(&mlx, &scene, 0);
	return (0);
}
