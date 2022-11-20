/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:01:17 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/12 15:27:28 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes/intersect.h"
#include "vec.h"

// t = (p0 - l). n / l . n
t_intersection *plane_intersection(t_plane_attr *plane, t_ray *ray, int x, int y)
{
	double          denom;
	t_vec3         *sub;
	double          t;
	t_intersection *intersection;

	denom = vec3_dot_product(&ray->direction, &plane->orientation);
	if (denom > 1e-6)
	{
		sub = vec3_sub(&plane->coordinates, &ray->origin, NULL, NULL);
		t = vec3_dot_product(sub, &plane->orientation) / denom;
		if (t < 0)
			return (NULL);
		intersection = ft_calloc(1, sizeof(t_intersection));
		intersection->shape = ft_calloc(1, sizeof(t_shape));
		intersection->shape->type = PLANE;
		intersection->shape->attr = plane;
		intersection->x = x;
		intersection->y = y;
		intersection->t1 = t;
		intersection->t2 = t;
		return (intersection);
	}
	return (NULL);
}
