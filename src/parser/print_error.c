/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:52:18 by skantoni          #+#    #+#             */
/*   Updated: 2026/05/06 10:52:20 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	print_error(const char *prefix, const char *subject, const char *suffix)
{
	int	first;

	first = 1;
	if (prefix && *prefix)
	{
		ft_putstr_fd((char *)prefix, 2);
		first = 0;
	}
	if (subject && *subject)
	{
		if (!first)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd((char *)subject, 2);
		first = 0;
	}
	if (suffix && *suffix)
	{
		if (!first)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd((char *)suffix, 2);
	}
	ft_putstr_fd("\n", 2);
}
