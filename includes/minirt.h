/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:34:51 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/06 17:33:45 by pavelino         ###   ########.fr       */
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
# include "objects.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		wdh;
	int		hgt;
}	t_mlx;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	position;
	double	brightness;
	int		color;
}	t_light;

typedef struct s_ambient
{
	double	ratio;
	t_color		color;
}	t_ambient;

typedef struct s_scene
{
	char		**file;
	int			line_count;
	int			has_ambient;
	int			has_camera;
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;

	t_sphere		*spheres;
	t_plane			*planes;
	t_cylinder		*cylinders;
}	t_scene;

int		parse_extention(char *arg);
int		parse_minirt(char *av, t_scene *scene);
int		parse_ambient(char *line, t_scene *scene);
int		count_l(char *path);
int		read_file(char *av, t_scene *scene);
int		create_window(t_mlx *mlx);
int		clean(t_mlx *mlx, t_scene *scene, int status);
int		handle_escape(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		parse_camera(char *line);
int		count_str_array(char **str);
int 	count_tokens(char **tokens);
void	print_error(const char *prefix, const char *subject, const char *suffix);
void    free_split(char **str);
void    init(t_scene *scene, t_mlx *mlx);
void	free_str_array(char **str);
char	**tokenizer_info(char *line);

#endif
