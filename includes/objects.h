/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:46:20 by skantoni          #+#    #+#             */
/*   Updated: 2026/05/11 08:46:27 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;


typedef struct s_sphere
{
	t_vec3				center;
	double				diameter;
	int					color;
	struct s_sphere		*next;
}	t_sphere;

typedef struct s_plane
{
	t_vec3				point;
	t_vec3				normal;
	int					color;
	struct s_plane		*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3					center;
	t_vec3					normal;
	double					diameter;
	double					height;
	int						color;
	struct s_cylinder		*next;
}	t_cylinder;

#endif