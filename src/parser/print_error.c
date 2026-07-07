/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:52:18 by skantoni          #+#    #+#             */
/*   Updated: 2026/07/07 14:30:40 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
