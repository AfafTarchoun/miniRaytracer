/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:21:58 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 01:49:33 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#include "../libft/libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 10

char *get_next_line(int fd);
char *ft_line(int fd, char *backup);
char *handle_return(char **backup, char **line);
// void  *ft_calloc(size_t count, size_t size);
// size_t ft_strlen(const char *s);
// char  *ft_strjoin(char const *s1, char const *s2);
// char  *ft_strchr(const char *s, int c);
// char  *ft_substr(char const *s, unsigned int start, size_t len);
// size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
// char  *ft_strdup(const char *s1);

#endif
