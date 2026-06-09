/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:29:41 by skantoni          #+#    #+#             */
/*   Updated: 2026/06/09 16:33:17 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *guard)
{
	char		*buffer;
	char		*temp;
	ssize_t		lido;

	lido = 1;
	while (!ft_strchr(guard, '\n') && lido > 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		lido = read(fd, buffer, BUFFER_SIZE);
		if (lido < 0)
		{
			free(buffer);
			free(guard);
			return (NULL);
		}
		buffer[lido] = '\0';
		temp = guard;
		guard = ft_strjoin(guard, buffer);
		free(temp);
		free(buffer);
	}
	return (guard);
}
