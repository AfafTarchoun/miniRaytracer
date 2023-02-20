/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:23:19 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/05 22:19:19 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normals.h"
#include "matrix.h"
#include "parsing/parser.h"

t_vector	*normal_at_cy(t_cylinder *cy, t_point *w_point, void (*f)(void *))
{
	t_vector	*w_normal;
	t_point		*o_point;
	t_point		*n_point;

	o_point = matrix_tuple_4(cy->inv_transform,
			w_point, NULL, f);
	n_point = point_create(o_point->x, 0, o_point->z);
	w_normal = matrix_tuple_4(matrix_transpos_4(cy->inv_transform,
				NULL), n_point, matrix_free_4, free);
	w_normal->w = 0;
	w_normal = tuple_normalize_f(w_normal, free);
	free(o_point);
	return (w_normal);
}
