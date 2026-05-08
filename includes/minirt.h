/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:34:51 by skantoni          #+#    #+#             */
/*   Updated: 2026/05/06 09:34:52 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		wdh;
	int		hgt;
}	t_mlx;



int		parse_extention(char *arg);
int		parse_minirt(char *av);
int		count_l(char *path);
int		file_read(char *av);
int		create_window(t_mlx *mlx);
void	print_error(const char *prefix, const char *subject, const char *suffix);
#endif
