/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:07:24 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/13 23:55:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing/parser.h"

void free_tab(char **tab)
{
	int i =0;

	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_world *parse_light(char *line, t_world *world)
{
	char **tab;
	char **coord;
	int i;
	
	i = 0;
	world->light = ft_calloc(1, sizeof(t_light));
	tab = ft_split(line, ' ');
	coord = ft_split(tab[1], ',');
	while(coord[i])
		i++;
	if(i != 3)
		return (NULL);
	world->light->intensity = (double)atof(tab[2]);
	world->light->pos = vector_create((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	free_tab(coord);
	free_tab(tab);
	return (world);
}