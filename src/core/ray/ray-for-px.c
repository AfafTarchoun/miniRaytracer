/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-for-px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:35:38 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "point.h"
#include "ray.h"
#include "tuple.h"
#include "parsing/parser.h"

t_ray	*ray_at_px(t_camera *c, int px, int py)
{
	double	x_world;
	double	y_world;
	t_point	*p_on_canvas;
	t_ray	*ray;

	x_world = c->half_w - (px + 0.5) * c->psize;
	y_world = c->half_h - (py + 0.5) * c->psize;
	p_on_canvas = matrix_tuple_4(c->inv_transform,
			point_create(x_world, y_world, -1), NULL, free);
	ray = ft_calloc(1, sizeof(t_ray));
	ray->origin = matrix_tuple_4(c->inv_transform,
			point_create(0, 0, 0), NULL, free);
	ray->dir = tuple_normalize_f(
			tuple_sub_f(p_on_canvas, ray->origin, free, NULL), free);
	return (ray);
}
