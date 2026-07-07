/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:35:24 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/06 18:33:58 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	parse_ratio(char **tokens, int len)
{
	if (len != 3)
		return (1);
	if (!tokens)
		return (2);
	return(1);
}

int	parse_colors(char **tokens, int len)
{
	int	i;

	i = 0;
	if (len != 3)
		return (1);
	if (!tokens)
		return (9);
	//colors = ft_split(tokens[2], ',');
	return (1);
}

int	parse_ambient(char *line, t_scene *scene)
{
/*		 --Formato
	 A [ratio] [R,G,B]
*/
	char	**tokens;
	int		i;
	int		tokens_len;
	char *splited = ft_strdup(line);
	tokens = ft_split(splited, ' ');
	i = 0;
	if (scene->has_ambient)
	{
		free_str_array(tokens);
		print_error("Error", "Verifique a luz ambiente!", "verifique se há duplicatas");
		return (1);
	}
	tokens_len = count_str_array(tokens);
	printf("tokens_len = %d\n", tokens_len);
	if (!parse_ratio(tokens, tokens_len) || !parse_colors(tokens, tokens_len))
	{
		free_str_array(tokens);
		return (printf("Erro nas configuracoes de ambiente"), 1);
	}
/* 	scene->ambient.color.r = ft_atoi(colors[0]);
	scene->ambient.color.g = ft_atoi(colors[1]);
	scene->ambient.color.b = ft_atoi(colors[2]); */
	//scene->ambient.ratio = atof(tokens[1]);
	//printf("Ratio -> %f\n", scene->ambient.ratio);
	scene->has_ambient = 1;
	return (0);
}
