/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minirt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:09:44 by skantoni          #+#    #+#             */
/*   Updated: 2026/05/07 12:09:46 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static int	line_empety(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

int	count_l(char *path)
{
	int		count;
	char	*linha;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		linha = get_next_line(fd);
		if (linha)
		{
			if (!(line_empety(linha)))
				count++;
			free(linha);
		}
		else
			break ;
	}
	close (fd);
	return (count);
}

int	read_file(char *av, t_scene *scene)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av, O_RDONLY);
	i = 0;
	scene->line_count = count_l(av);
	scene->file = malloc(sizeof(char *) * (scene->line_count + 1));
	if (!scene->file)
		return (1);
	while (i < scene->line_count)
	{
		line = ft_strtrim((get_next_line(fd)), " \n\t");
		if (!(line_empety(line)))
			scene->file[i++] = line;
		else
			free(line);
	}
	scene->file[i] = NULL;
	i = 0;
	while (scene->file[i])
	{
		printf("linha : %s\n", scene->file[i]);
		i++;
	}
	close(fd);
	return (0);
}
