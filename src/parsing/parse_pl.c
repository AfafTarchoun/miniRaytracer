/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:22:21 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/06 19:05:25 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "matrix.h"
#include "utils.h"

t_plane	*fill_plane(char **coord, char **orio, char **col)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	pl->origin = point_create(ft_atof(coord[0]),
			ft_atof(coord[1]), ft_atof(coord[2]));
	pl->orient = point_create(ft_atof(orio[0]),
			ft_atof(orio[1]), ft_atof(orio[2]));
	pl->material = material();
	free(pl->material->color);
	pl->material->color = point_create(ft_atof(col[0]),
			ft_atof(col[1]), ft_atof(col[2]));
	pl->material->color = tuple_div_f(pl->material->color, 255, free);
	pl->transform = matrix_translate_creat_4(
			point_create(pl->origin->x, pl->origin->y, pl->origin->z), free);
	pl->transform = matrix_mul_4_f(pl->transform, matrix_rotate_x_4
			(deg_to_rad(pl->orient->x)), matrix_free_4, matrix_free_4);
	pl->transform = matrix_mul_4_f(pl->transform, matrix_rotate_y_4
			(deg_to_rad(pl->orient->y)), matrix_free_4, matrix_free_4);
	pl->transform = matrix_mul_4_f(pl->transform, matrix_rotate_z_4
			(deg_to_rad(pl->orient->z)), matrix_free_4, matrix_free_4);
	pl->inv_transform = matrix_invert_4(pl->transform);
	return (pl);
}
	// char		**tab;//info[0]
	// char		**coord;//info[1]
	// char		**orio;//info[2]
	// char		**col;//info[3]

t_entity	*parse_plane(char *line)
{
	t_plane		*pl;
	t_entity	*shape;
	char		**info[4];

	shape = ft_calloc(1, sizeof(t_entity));
	info[0] = ft_split(line, ' ');
	info[0] = test_field(info[0], 4);
	info[1] = ft_split(info[0][1], ',');
	info[1] = test_field(info[1], 3);
	info[2] = ft_split(info[0][2], ',');
	info[2] = test_field(info[2], 3);
	info[3] = ft_split(info[0][3], ',');
	info[3] = test_field(info[3], 3);
	pl = fill_plane(info[1], info[2], info[3]);
	shape->type = PLANE;
	shape->obj = pl;
	free_tab(info[1]);
	free_tab(info[2]);
	free_tab(info[3]);
	free_tab(info[0]);
	return (shape);
}
