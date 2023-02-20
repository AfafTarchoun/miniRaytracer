/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:16:37 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "utils.h"

double	**cy_transformation(t_cylinder *cy)
{
	cy->transform = matrix_mul_4_f(matrix_translate_creat_4(cy->coord, NULL),
			matrix_scale_4(vector_create(cy->diameter / 2,
					cy->diameter / 2, cy->diameter / 2), free),
			matrix_free_4, matrix_free_4);
	cy->transform = matrix_mul_4_f(cy->transform, matrix_rotate_x_4
			(deg_to_rad(cy->orient->x)), matrix_free_4, matrix_free_4);
	cy->transform = matrix_mul_4_f(cy->transform, matrix_rotate_y_4
			(deg_to_rad(cy->orient->y)), matrix_free_4, matrix_free_4);
	cy->transform = matrix_mul_4_f(cy->transform, matrix_rotate_z_4
			(deg_to_rad(cy->orient->z)), matrix_free_4, matrix_free_4);
	return (cy->transform);
}

t_cylinder	*fill_cylinder(char **tab, char **coord, char **orio, char **col)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	cy->origin = point_create(0, 0, 0);
	cy->diameter = ft_atof(tab[3]);
	cy->height = ft_atof(tab[4]);
	cy->coord = point_create(ft_atof(coord[0]),
			ft_atof(coord[1]), ft_atof(coord[2]));
	cy->orient = point_create(ft_atof(orio[0]),
			ft_atof(orio[1]), ft_atof(orio[2]));
	cy->material = material();
	free(cy->material->color);
	cy->material->color = point_create(ft_atof(col[0]),
			ft_atof(col[1]), ft_atof(col[2]));
	cy->material->color = tuple_div_f(cy->material->color, 255, free);
	cy->transform = cy_transformation(cy);
	cy->inv_transform = matrix_invert_4(cy->transform);
	return (cy);
}

char	**test_field(char **tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != nb)
		return (NULL);
	i = 0;
	return (tab);
}

	// char		**tab;//info[0]
	// char		**coord;//info[1]
	// char		**orio;//info[2]
	// char		**col;//info[3]
t_entity	*parse_cylinder(char *line)
{
	t_cylinder	*cy;
	t_entity	*shape;
	char		**info[4];

	info[0] = ft_split(line, ' ');
	info[0] = test_field(info[0], 6);
	if (comma_check(info[0], 3) == 0 || comma_check(info[0], 4) == 0)
		return (free_return(info[0]));
	info[1] = ft_split(info[0][1], ',');
	info[1] = test_field(info[1], 3);
	info[2] = ft_split(info[0][2], ',');
	info[2] = test_field(info[2], 3);
	info[3] = ft_split(info[0][5], ',');
	info[3] = test_field(info[3], 3);
	cy = fill_cylinder(info[0], info[1], info[2], info[3]);
	shape = ft_calloc(1, sizeof(t_entity));
	shape->type = CYLINDER;
	shape->obj = cy;
	free_tab(info[3]);
	free_tab(info[2]);
	free_tab(info[1]);
	free_tab(info[0]);
	return (shape);
}
