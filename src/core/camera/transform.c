/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:49:02 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrix.h"
#include "point.h"
#include "tuple.h"

typedef struct s_camera_vars
{
	t_vector	*forward;
	t_vector	*left;
	t_vector	*true_up;
	double		**orientation;
	double		**tmp;
	double		**tmp2;
}	t_camera_vars;

double	**__camera_transform__(t_camera_vars *vars, t_point *from)
{
	free(vars->forward);
	free(vars->left);
	free(vars->true_up);
	vars->tmp = matrix_translate_creat_4(point_create
			(-from->x, -from->y, -from->z), free);
	vars->tmp2 = matrix_mul_4(vars->orientation, vars->tmp);
	matrix_free_4(vars->orientation);
	matrix_free_4(vars->tmp);
	return (vars->tmp2);
}

double	**camera_transform(t_point *from, t_vector *to, t_vector *up)
{
	t_camera_vars	vars;

	vars.forward = tuple_normalize_f(tuple_sub(to, from), free);
	vars.left = tuple_cross_f(vars.forward, tuple_normalize(up), NULL, free);
	vars.true_up = tuple_cross(vars.left, vars.forward);
	vars.orientation = matrix_identity_4();
	vars.orientation[0][0] = vars.left->x;
	vars.orientation[0][1] = vars.left->y;
	vars.orientation[0][2] = vars.left->z;
	vars.orientation[1][0] = vars.true_up->x;
	vars.orientation[1][1] = vars.true_up->y;
	vars.orientation[1][2] = vars.true_up->z;
	vars.orientation[2][0] = -vars.forward->x;
	vars.orientation[2][1] = -vars.forward->y;
	vars.orientation[2][2] = -vars.forward->z;
	return (__camera_transform__(&vars, from));
}
