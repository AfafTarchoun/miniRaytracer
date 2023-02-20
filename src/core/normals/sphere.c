/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:55:35 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/05 22:16:41 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normals.h"
#include "matrix.h"
#include "parsing/parser.h"

t_vector	*normal_at_sphere(t_sphere *sphere,
				t_point *w_point, void (*f)(void *))
{
	t_vector	*w_normal;
	t_point		*o_point;

	o_point = matrix_tuple_4(sphere->inv_transform,
			w_point, NULL, f);
	w_normal = tuple_sub(o_point, sphere->origin);
	w_normal = matrix_tuple_4(matrix_transpos_4
			(sphere->inv_transform, NULL),
			w_normal, matrix_free_4, free);
	w_normal->w = 0;
	w_normal = tuple_normalize_f(w_normal, free);
	free(o_point);
	return (w_normal);
}
