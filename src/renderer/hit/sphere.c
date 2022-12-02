/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 21:41:56 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "entity.h"
#include "hit.h"
#include "material.h"
#include "math.h"
#include "matrix.h"
#include "point.h"
#include "ray.h"
#include "tuple.h"
#include <stdio.h>

t_hit *hit_sphere_create(float t1, float t2, t_sphere *s)
{
	t_hit *hit;

	hit = ft_calloc(1, sizeof(t_hit));
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = SPHERE;
	hit->t1 = t1;
	hit->t2 = t2;
	if (s)
		hit->entity->obj =
		    sphere(point_create(s->origin->x, s->origin->y, s->origin->z), material(), s->raduis);
	return (hit);
}

t_hit *ray_sphere_hit(t_ray *ray, t_sphere *s)
{
	t_hit    *hit;
	t_vector *sphere_to_ray;
	float     a;
	float     b;
	float     c;
	float     disc;

	ray = ray_transform(ray, matrix_invert_4(s->transform), NULL, matrix_free_4);
	sphere_to_ray = tuple_sub(ray->origin, s->coord);
	a = tuple_dot(ray->dir, ray->dir);
	b = 2.0f * tuple_dot(ray->dir, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	// pow(s->raduis, 2);
	free(sphere_to_ray);
	ray_delete(ray);
	disc = ((b * b) - (4 * a * c));
	if (disc < 0)
		return (NULL);
	hit = hit_sphere_create(0, 0, s);
	hit->t1 = (-b - sqrt(disc)) / 2 * a;
	hit->t2 = (-b + sqrt(disc)) / 2 * a;
	return (hit);
}
 