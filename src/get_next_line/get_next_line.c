/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:28:36 by skantoni          #+#    #+#             */
/*   Updated: 2025/08/08 17:28:41 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_substr(char const *str, size_t s, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (s < len)
		sub[i++] = str[s++];
	sub[i] = '\0';
	return (sub);
}

char	*r_line(char *guard)
{
	int	len;

	len = 0;
	while (guard[len] != '\n' && guard[len] != '\0')
	{
		len++;
	}
	if (guard[len] == '\n')
		return (ft_substr(guard, 0, len + 1));
	else
		return (ft_substr(guard, 0, len));
}

char	*align_guard(char *resto)
{
	char	*aligned;
	char	*newline;
	char	*temp;

	temp = resto;
	newline = ft_strchr(resto, '\n');
	if (!newline)
	{
		free(resto);
		return (NULL);
	}
	aligned = ft_strdup(newline + 1);
	free(temp);
	return (aligned);
}

char	*get_next_line(int fd)
{
	static char	*guard;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (!guard)
		guard = ft_strdup("");
	guard = ft_read(fd, guard);
	if (!guard)
		return (NULL);
	if (guard[0] <= 0)
	{
		free(guard);
		guard = NULL;
		return (NULL);
	}
	line = r_line(guard);
	guard = align_guard(guard);
	return (line);
}
