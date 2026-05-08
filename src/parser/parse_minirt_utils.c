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
