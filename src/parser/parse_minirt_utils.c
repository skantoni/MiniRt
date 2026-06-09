/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minirt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:09:44 by skantoni          #+#    #+#             */
/*   Updated: 2026/06/09 13:29:46 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"	


char	**tokenizer_info(char *line)
{
	char	**tokens;

	if (!line)
		return (NULL);
	tokens = ft_split(line, ' ');
	return (tokens);
}

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

	fd = open(av, O_RDONLY);
	i = 0;
	scene->line_count = count_l(av);
	scene->file = malloc(sizeof(char *) * (scene->line_count + 1));
	if (!scene->file)
		return (1);
	while (i < scene->line_count)
	{
		line = ft_strtrim((get_next_line(fd)), " \n\t");
		if (!(line_empety(line)) && (line[0] != '#'))
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
