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
#include <stdlib.h>

int	parse_ambient(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->has_ambient)
	{
		print_error("Error", "check the ambient light!", "check whether it exists or not and if has double");
		return (1);
	}
	while (tokens[i])
	{
		printf("tokens[%i] ==> %s\n", i, tokens[i]);
		i++;
	}
	scene->ambient.ratio = atof(tokens[1]); 
	printf("Ratio -> %f\n", scene->ambient.ratio);
	scene->has_ambient = 1;
	return (0);
}
