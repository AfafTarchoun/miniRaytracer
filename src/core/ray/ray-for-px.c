/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-for-px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:35:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 20:37:54 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "point.h"
#include "ray.h"
#include "tuple.h"

t_ray *ray_at_px(t_camera *c, int px, int py)
{
	float    xoffsite;
	float    yoffsite;
	float    x_world;
	float    y_world;
	t_point *p_on_canvas;
	t_ray   *ray;

	xoffsite = ((float) px + 0.5f) * c->psize;
	yoffsite = ((float) py + 0.5f) * c->psize;
	x_world = c->half_w - xoffsite;
	y_world = c->half_h - yoffsite;
	p_on_canvas = matrix_tuple_4(matrix_invert_4(c->transform), point_create(x_world, y_world, -1), matrix_free_4, free);
	ray = ft_calloc(1, sizeof(t_ray));
	ray->origin = matrix_tuple_4(matrix_invert_4(c->transform), point_create(0, 0, 0), matrix_free_4, free);
	ray->dir = tuple_normalize_f(tuple_sub(p_on_canvas, ray->origin), free);
	return (ray);
}
