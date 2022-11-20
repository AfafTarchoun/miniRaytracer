/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:39:50 by habouiba          #+#    #+#             */
/*   Updated: 2022/10/01 15:02:57 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
	char  *buffer;
	size_t i;
	size_t len;

	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	buffer = (char *) malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return ((void *) buffer);
}
