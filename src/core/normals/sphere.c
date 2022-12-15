/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:55:35 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/12 03:52:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing/parser.h"

t_vector *normal_at_sphere(t_sphere *sphere, t_point *w_point, void (*f)(void *))
{
	t_vector *w_normal;
	t_point  *o_point;

	o_point = matrix_tuple_4(matrix_invert_4(sphere->transform), w_point, matrix_free_4, f);
	w_normal = tuple_sub(o_point, sphere->origin);
	w_normal = matrix_tuple_4(matrix_transpos_4(matrix_invert_4(sphere->transform), matrix_free_4), w_normal, matrix_free_4, free);
	w_normal->w = 0;
	w_normal = tuple_normalize_f(w_normal, free);
	sphere->normal = w_normal;
	return (w_normal);
}

// t_vector *nrml_sp(t_sphere *sp, t_ray *ray)
// {
// 	t_vector *normal;
// 	t_point  *hit;

// 	hit = ray_sphere_hit(ray, sp);
// 	normal = tuple_sub(sp->sphere_to_ray, sp->origin);
// 	normal = tuple_normalize(normal);
// 	return(normal);
// }
