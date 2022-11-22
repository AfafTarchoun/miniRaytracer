/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:55:48 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 23:09:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes/intersect.h"
#include "vec.h"
#include <stdio.h>

t_intersection *sphere_intersection(t_sphere_attr *sphere, t_ray *ray, int x, int y)
{
	t_vec3         *oc;
	float           a;
	float           b;
	float           c;
	t_intersection *intersection;

	oc = vec3_sub(&ray->origin, &sphere->coordinates, NULL, NULL);
	a = vec3_dot_product(&ray->direction, &ray->direction);
	b = 2.0 * vec3_dot_product(oc, &ray->direction);
	c = vec3_dot_product(oc, oc) - pow(sphere->diameter / 2, 2);
	if ((b * b - 4 * a * c) < 0.0f)
		return (NULL);
	intersection = ft_calloc(1, sizeof(t_intersection));
	if (NOT intersection)
		return (NULL);
	intersection->t1 = -b + sqrt(pow(b, 2) - (4 * a * c) * M_PI / 180);
	intersection->t2 = -b - sqrt(pow(b, 2) - (4 * a * c) * M_PI / 180);
	// intersection->t1 = -b + sqrt(b * b - 4 * a * c);
	// intersection->t2 = -b - sqrt(b * b - 4 * a * c);
	if (intersection->t1 < 0 || intersection->t2 < 0)
	{
		free(intersection);
		return (NULL);
	}
	intersection->shape = ft_calloc(1, sizeof(t_shape));
	intersection->shape->type = SPHERE;
	intersection->shape->attr = sphere;
	intersection->x = x;
	intersection->y = y;
	return (intersection);
}
