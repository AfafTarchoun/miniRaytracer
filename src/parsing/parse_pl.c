/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:22:21 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/13 23:19:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/parsing/parser.h"

t_entity *parse_plane(char *line)
{
	t_plane *pl;
	t_entity *shape;
	char **tab;
	char **coord;
	char **orio;
	char **col;
	int i;

	i = 0;
	shape = ft_calloc(1, sizeof(t_entity));
	pl = malloc(sizeof(t_plane));
	pl->material = malloc(sizeof(t_material));
	tab = ft_split(line, ' ');
	coord = ft_split(tab[1], ',');
	while(coord[i])
		i++;
	if(i != 3)
		return (NULL);
	i = 0;
	orio = ft_split(tab[2], ',');
	while(orio[i])
		i++;
	if(i != 3)
		return (NULL);
	i = 0;
	col = ft_split(tab[3], ',');
	while(orio[i])
		i++;
	if(i != 3)
		return (NULL);
	pl->origin = point_create((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	pl->orient = point_create((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	pl->material->color = point_create((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	shape->type = PLANE;
	shape->obj = pl;
	free_tab(coord);
	free_tab(orio);
	free_tab(col);
	free_tab(tab);
	return (shape);
}