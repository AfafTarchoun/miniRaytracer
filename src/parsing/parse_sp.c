/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:20:28 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/13 23:17:47 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing/parser.h"

t_entity *parse_sphere(char *line)
{
	t_sphere *sp;
	t_entity *shape;
	int i;
	char **tab;
	char **coord;
	char **col;
	float rad;
	
	i = 0;
	shape = ft_calloc(1, sizeof(t_entity));
	sp = malloc(sizeof(t_sphere));
	sp->material = malloc(sizeof(t_material));
	tab = ft_split(line, ' ');
	coord = ft_split(tab[1], ',');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	col = ft_split(tab[3], ',');
	while(col[i])
		i++;
	if(i != 3)
		return 0;
	sp->raduis = (double)atof(tab[2]);
	rad = sp->raduis / 2;
	sp->origin = point_create(0, 0, 0);
	sp->coord = point_create((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	sp->material->color = point_create((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	shape->type = SPHERE;
	shape->obj = sp;
	((t_sphere *) shape->obj)->transform = matrix_mul_4_f(matrix_translate_creat_4(sp->coord, free),
		matrix_scale_4(vector_create(rad, rad, rad), free), matrix_free_4, matrix_free_4);
	free_tab(coord);
	free_tab(col);
	free_tab(tab);
	return (shape);
}