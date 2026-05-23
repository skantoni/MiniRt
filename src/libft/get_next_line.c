/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavelino <pavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:44:08 by pavelino          #+#    #+#             */
/*   Updated: 2025/12/01 12:36:42 by pavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *dados)
{
	char	*buffer;
	ssize_t	read_byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(dados, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		dados = ft_strjoin(dados, buffer);
	}
	free(buffer);
	return (dados);
}

static char	*extrair_linha(char *dados)
{
	int	i;

	i = 0;
	if (!dados || !dados[0])
		return (NULL);
	while (dados[i] && dados[i] != '\n')
		i++;
	return (ft_substr(dados, 0, i));
}

static char	*atualizar_linha(char *dados)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!dados)
		return (NULL);
	while (dados[i] && dados[i] != '\n')
		i++;
	if (dados[i] == '\n')
		i++;
	if (!dados[i])
	{
		free(dados);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(dados + i) + 1));
	while (dados[i])
		line[j++] = dados[i++];
	line[j] = '\0';
	free(dados);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*dados;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dados = read_file(fd, dados);
	line = extrair_linha(dados);
	dados = atualizar_linha(dados);
	return (line);
}
