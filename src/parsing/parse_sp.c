/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:20:28 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"

void	*free_return(char **tab)
{
	free_tab(tab);
	return (NULL);
}

t_sphere	*fill_sphere(char **tab, char **coord, char **col)
{
	t_sphere	*sp;
	double		rad;

	sp = malloc(sizeof(t_sphere));
	sp->raduis = ft_atof(tab[2]);
	rad = sp->raduis / 2;
	sp->origin = point_create(0, 0, 0);
	sp->coord = point_create(ft_atof(coord[0]),
			ft_atof(coord[1]), ft_atof(coord[2]));
	sp->material = material();
	free(sp->material->color);
	sp->material->color = point_create(ft_atof(col[0]),
			ft_atof(col[1]), ft_atof(col[2]));
	sp->material->color = tuple_div_f(sp->material->color, 255, free);
	sp->transform = matrix_mul_4_f(matrix_translate_creat_4(sp->coord, NULL),
			matrix_scale_4(vector_create(rad, rad, rad), free),
			matrix_free_4, matrix_free_4);
	sp->inv_transform = matrix_invert_4(sp->transform);
	return (sp);
}

t_entity	*parse_sphere(char *line)
{
	t_sphere	*sp;
	t_entity	*shape;
	char		**tab;
	char		**coord;
	char		**col;

	tab = ft_split(line, ' ');
	tab = test_field(tab, 4);
	if (comma_check(tab, 2) == 0)
	{
		free(tab);
		return (NULL);
	}
	coord = ft_split(tab[1], ',');
	coord = test_field(coord, 3);
	col = ft_split(tab[3], ',');
	col = test_field(col, 3);
	sp = fill_sphere(tab, coord, col);
	shape = ft_calloc(1, sizeof(t_entity));
	shape->type = SPHERE;
	shape->obj = sp;
	free_tab(coord);
	free_tab(col);
	free_tab(tab);
	return (shape);
}
