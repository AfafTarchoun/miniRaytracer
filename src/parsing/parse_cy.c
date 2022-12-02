/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:16:37 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/01 21:13:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/parsing/parser.h"

t_entity *parse_cylinder(char *line)
{
	t_cylinder *cy;
	t_entity *shape;
	char **tab;
	char **coord;
	char **orio;
	char **col;
	int i;
	
	i = 0;
	shape = ft_calloc(1, sizeof(t_entity));
	cy = malloc(sizeof(t_cylinder));
	cy->material = malloc(sizeof(t_material));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	orio = ft_split(tab[2], ' ');
	while(orio[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	col = ft_split(tab[5], ' ');
	while(col[i])
		i++;
	if(i != 3)
		return NULL;
	cy->diameter = (double)atof(tab[3]);
	cy->height = (double)atof(tab[4]);
	cy->origin = vector_create((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	cy->orient = vector_create((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	cy->material->color = vector_create((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	shape->type = CYLINDER;
	shape->obj = cy;
	free_tab(col);
	free_tab(orio);
	free_tab(coord);
	free_tab(tab);
	return (shape);
}