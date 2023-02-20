/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:53:26 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/27 04:17:52 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normals.h"
#include "matrix.h"
#include "vector.h"
#include "tuple.h"

t_vector	*normal_at_plane(t_plane *plane,
		t_point *w_point, void (*f)(void *))
{
	t_vector	*w_normal;

	w_normal = vector_create(0, 1, 0);
	w_normal = matrix_tuple_4(matrix_transpos_4(plane->inv_transform, NULL),
			w_normal, matrix_free_4, free);
	w_normal->w = 0;
	w_normal = tuple_normalize_f(w_normal, free);
	if (f)
		f(w_point);
	return (w_normal);
}
