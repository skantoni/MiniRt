/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:37:37 by pavelino          #+#    #+#             */
/*   Updated: 2026/05/02 12:48:47 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_mlx	*wind;
	int		fd;

	if (ac != 2)
		return (print_error("minirt", "Insira", "./miniRT scene.rt"), 1);
	if (parse_minirt(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\n", 6), 1);
	//write(1, "Sucessfull\n", 11);
	wind = malloc(sizeof(t_mlx));
	if (!wind)
		return (1);
	create_window(wind);
	return (0);
}
