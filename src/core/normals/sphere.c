/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:55:35 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 16:00:31 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "normals.h"
#include "tuple.h"

t_vector *normal_at_sphere(t_sphere *sphere, t_point *w_point, void (*f)(void *))
{
	t_vector *w_normal;
	t_point  *o_point;

	o_point = matrix_tuple_4(matrix_invert_4(sphere->transform), w_point, matrix_free_4, f);
	w_normal = tuple_sub(o_point, sphere->origin);
	w_normal = matrix_tuple_4(matrix_transpos_4(matrix_invert_4(sphere->transform), matrix_free_4), w_normal, matrix_free_4, free);
	w_normal->w = 0;
	w_normal = tuple_normalize_f(w_normal, free);
	return (w_normal);
}
