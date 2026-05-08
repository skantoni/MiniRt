/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:21:10 by skantoni          #+#    #+#             */
/*   Updated: 2025/08/08 17:21:12 by skantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
//size_t	ft_strlen(char *str);
//char	*ft_strdup(char	*str);
//char	*ft_strjoin(char *s1, char *s2);
//char	*ft_strchr(char *str, char c);
char	*ft_read(int fd, char *guard);
//char	*ft_substr(const char *str, size_t s, size_t len);
char	*r_line(char *guard);
char	*align_guard(char *resto);
/* 
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
char	*ft_read(int fd, char *guard);
char	*ft_substr(const char *str, size_t s, size_t len);
char	*r_line(char *guard);
char	*align_guard(char *resto); */
#endif
