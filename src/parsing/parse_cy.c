/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:16:37 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/09 06:51:04 by atarchou         ###   ########.fr       */
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
	cy->origin = point_create(0, 0, 0);
	cy->diameter = (double)atof(tab[3]);
	cy->height = (double)atof(tab[4]);
	cy->coord = point_create((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	cy->orient = point_create((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	cy->material->color = point_create((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	// ((t_cylinder *) shape->obj)->transform = matrix_mul_4_f(matrix_translate_creat_4(cy->coord, free),
	// 	matrix_scale_4(vector_create(10, 10, 10), free), matrix_free_4, matrix_free_4);
	shape->type = CYLINDER;
	shape->obj = cy;
	free_tab(col);
	free_tab(orio);
	free_tab(coord);
	free_tab(tab);
	return (shape);
}