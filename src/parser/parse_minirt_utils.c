/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minirt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:09:44 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/10 17:19:30 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"	

static int	line_empety(char *str)
{
	int	i;

	if (!str)
		return (1);
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
	char	*line;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (!(line_empety(line)) && line[0] != '#')
				count++;
			free(line);
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

	scene->line_count = count_l(av);
	if (scene->line_count <= 0)
		return (printf("Error\nFile %s is empty", av), 1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nFailed to open file %s", av), 1);
	scene->file = malloc(sizeof(char *) * (scene->line_count + 1));
	if (!scene->file)
		return (close(fd), 1);
	i = 0;
	while (i < scene->line_count) {
		if (!(line = get_next_line(fd)))
			break;
		line = ft_strtrim(line, " \n\t");
		if (!(line_empety(line)) && (line[0] != '#'))
			scene->file[i++] = line;
		else
			free(line);
	}
	scene->file[i] = NULL;
	return (close(fd), 0);
}
