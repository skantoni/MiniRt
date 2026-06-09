/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:35:24 by skantoni          #+#    #+#             */
/*   Updated: 2026/06/09 13:34:17 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	parse_ambient(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->has_ambient != 1)
	{
		print_error("minirt", "check the ambient light!", "check if it exists or if it has double");
		return (1);
	}
	while (tokens[i])
	{
		printf("tokens[%i] ==> %s Fim \n", i, tokens[i]);
		i++;
	}
	free_split(tokens);
	return (0);
}
