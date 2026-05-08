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
			count++;
			free(linha);
		}
		else
			break ;
	}
	close (fd);
	return (count);
}

int	file_read(char *av)
{
	char	**map;
	int		fd;
	int		i;
	int		nl;

	fd = open(av, O_RDONLY);
	i = 0;
	nl = count_l(av);
	map = malloc(sizeof(char *) * nl + 1);
	if (!map)
		return (1);
	while (i < nl)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (0);
}
