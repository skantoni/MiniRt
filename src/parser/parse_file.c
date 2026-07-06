/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:35:24 by skantoni          #+#    #+#             */
/*   Updated: 2026/06/09 17:08:24 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	parse_ratio(char *ratio)
{
	if (!ratio)
		return (2);
	return(1);
}

int	parse_colors(char **color)
{
	if (!color)
		return (9);
	return (1);
}

int	parse_ambient(char *line, t_scene *scene)
{
/*		 --Formato
	 A [ratio] [R,G,B]
*/
	char	**tokens;
	char	**colors;
	tokens = tokenizer_info(line);

	int	i;

	i = 0;
	if (scene->has_ambient)
	{
		print_error("Error", "Verifique a luz ambiente!", "verifique se há duplicatas");
		return (1);
	}
	colors = ft_split(tokens[2], ',');
	if (parse_ratio(tokens[1]) || parse_colors(colors))
		return (1);
	scene->ambient.color.r = ft_atoi(colors[0]);
	scene->ambient.color.g = ft_atoi(colors[1]);
	scene->ambient.color.b = ft_atoi(colors[2]);

	scene->ambient.ratio = atof(tokens[1]);
	
	printf("Ratio -> %f\n", scene->ambient.ratio);
	scene->has_ambient = 1;
	return (0);
}
