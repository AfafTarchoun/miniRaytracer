/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:17:44 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/27 09:37:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing/parser.h"

t_world *parse_ambient(char *line, t_world *world)
{
	char **tab;
	char **col;
	int i;
	
	i = 0;
	world->alight = ft_calloc(1, sizeof(t_a_light));
	tab = ft_split(line, '|');
	col = ft_split(tab[2], ' ');
	while(col[i])
		i++;
	if(i != 3)
		return NULL;
	world->alight->ratio = (double)atof(tab[1]);
	world->alight->material->color = vector_create((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	free_tab(col);
	free_tab(tab);
	return (world);
}