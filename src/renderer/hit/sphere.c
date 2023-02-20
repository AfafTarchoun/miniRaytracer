/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:43 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
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

t_hit	*hit_sphere_create(double t1, double t2, t_sphere *s)
{
	t_hit		*hit;

	hit = ft_calloc(1, sizeof(t_hit));
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = SPHERE;
	hit->entity->obj = s;
	hit->t1 = t1;
	hit->t2 = t2;
	return (hit);
}

void	print_tuple(t_tuple *tpl)
{
	printf("\n--\nx = %lf\ny = %lf\nz = %lf", tpl->x, tpl->y, tpl->z);
}

t_hit	*fill_hit(t_ray *ray, t_sphere *s, t_vector *s_r, t_hit *hit)
{
	hit->eyev = tuple_negate(ray->dir);
	if (which_positive_and_low(hit->t1, hit->t2) > 0)
	{
		hit->hitpoint = tuple_add_f(s_r, tuple_scale(ray->dir,
					which_positive_and_low(hit->t1, hit->t2)), 0, free);
		hit->norm = normal_at_sphere(s, hit->hitpoint, 0);
	}
	else
		hit->hitpoint = NULL;
	return (hit);
}

t_hit	*ray_sphere_hit(t_ray *ray, t_sphere *s)
{
	t_hit		*hit;
	t_vector	*sphere_to_ray;
	t_solution	*res;
	double		disc;

	res = ft_calloc(1, sizeof(t_solution));
	ray = ray_transform(ray, s->inv_transform, NULL, NULL);
	sphere_to_ray = tuple_sub(ray->origin, s->origin);
	res->a = tuple_dot(ray->dir, ray->dir);
	res->b = 2.0f * tuple_dot(ray->dir, sphere_to_ray);
	res->c = tuple_dot(sphere_to_ray, sphere_to_ray) - pow(s->raduis / 2, 2);
	disc = ((res->b * res->b - 4 * res->a * res->c));
	if (disc < 0)
	{
		free(sphere_to_ray);
		free_res_ray(ray, res);
		return (NULL);
	}
	hit = hit_sphere_create(0, 0, s);
	hit->t1 = (-res->b - sqrt(disc)) / (2.0f * res->a);
	hit->t2 = (-res->b + sqrt(disc)) / (2.0f * res->a);
	hit = fill_hit(ray, s, sphere_to_ray, hit);
	free(sphere_to_ray);
	free_res_ray(ray, res);
	return (hit);
}
