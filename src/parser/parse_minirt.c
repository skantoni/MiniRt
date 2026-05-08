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

int	parse_file(char *av)
{
	if (file_read(av))
		return (1);
	return (0);
}

int	parse_minirt(char *av)
{
	if (parse_extention(av))
		return (1);
	if (parse_file(av))
		return (1);
	return (0);
}
