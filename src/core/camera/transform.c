/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:49:02 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 21:06:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrix.h"
#include "point.h"
#include "tuple.h"

float **camera_transform(t_point *from, t_vector *to, t_vector *up)
{
	t_vector *forward;
	t_vector *left;
	t_vector *true_up;
	float   **orientation;
	float   **tmp;
	float   **tmp2;

	forward = tuple_normalize_f(tuple_sub(to, from), free);
	left = tuple_cross_f(forward, tuple_normalize(up), NULL, free);
	true_up = tuple_cross(left, forward);
	orientation = matrix_identity_4();
	orientation[0][0] = left->x;
	orientation[0][1] = left->y;
	orientation[0][2] = left->z;
	orientation[1][0] = true_up->x;
	orientation[1][1] = true_up->y;
	orientation[1][2] = true_up->z;
	orientation[2][0] = -forward->x;
	orientation[2][1] = -forward->y;
	orientation[2][2] = -forward->z;
	free(forward);
	free(left);
	free(true_up);
	tmp = matrix_translate_creat_4(point_create(-from->x, -from->y, -from->z), free);
	tmp2 = matrix_mul_4(orientation, tmp);
	matrix_free_4(orientation);
	matrix_free_4(tmp);
	return (tmp2);
}
