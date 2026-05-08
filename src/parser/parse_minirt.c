/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_miniRT.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:12:00 by pavelino          #+#    #+#             */
/*   Updated: 2026/05/02 12:48:10 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

int	parse_extention(char *av)
{
	char	*str;

	str = ft_strrchr(av, '.');
	if (ft_strncmp(".rt", str, 4) == 0)
		return (0);
	print_error("minirt", "Verifique a extensao do arquivo", NULL);
	return (1);
}

/* int	parse_file(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	
} */

int	parse_minirt(char *av)
{
	char	**map;
	int		fd;
	int		i;
	int		nl;

	if (parse_extention(av))
		return (1);

	fd = open(av, O_RDONLY);
	i = 0;
	nl = count_l(av);
	//return (printf("nl = %d", nl), 1);
	map = malloc(sizeof(char *) * nl + 1);
	while (i < nl)
	{
		map[i] = get_next_line(fd);
		i++;
	}

	map[i] = NULL;
	i = 0;
	while(map[i])
	{
		printf("Linha %d : %s", i, map[i]);
		i++;
	}
	/*if (parse_file(av))
		return(1);
	*/
	return (0);
}
