/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/15 12:23:53 by atarchou         ###   ########.fr       */
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
#include "../../../include/parsing/parser.h"

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

void print_tuple(t_tuple *tpl)
{
	printf("\n--\nx = %lf\ny = %lf\nz = %lf", tpl->x, tpl->y, tpl->z);
}

t_tuple *colooor(t_tuple *v)
{
    t_tuple *w;

    w = ft_calloc(1, sizeof(t_tuple));
    if (!w)
		return (w);
    w->x = v->x * 255;
    w->y = v->y * 255;
    w->z = v->z * 255;
    return (w);
}

double clamp(double d, double min, double max)
{
  double t = d < min ? min : d;
  return t > max ? max : t;
}

t_tuple *clamp_color(t_tuple *v)
{
	t_tuple *w;
	w = ft_calloc(1, sizeof(t_tuple));
    if (!w)
		return (w);
	w->x = clamp(v->x, 0.0f, 1.0f);
	w->y = clamp(v->y, 0.0f, 1.0f);
	w->z = clamp(v->z, 0.0f, 1.0f);
	return (w);
}

double max(double num1, double num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

t_hit *ray_sphere_hit(t_ray *ray, t_sphere *s, t_world *world)
{
	t_hit    *hit;
	t_vector *sphere_to_ray;
	t_vector *normal;
	t_vector *lightdir;
	float     a;
	float     b;
	float     c;
	float     disc;

	ray = ray_transform(ray, matrix_invert_4(s->transform), NULL, matrix_free_4);
	sphere_to_ray = tuple_sub(ray->origin, s->origin);
	a = tuple_dot(ray->dir, ray->dir);
	b = 2.0f * tuple_dot(ray->dir, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray) - pow(s->raduis/2,2);
	disc = ((b * b) - (4 * a * c));
	if (disc < 0)
		return (NULL);
	hit = hit_sphere_create(0, 0, s);
	hit->t1 = (-b - sqrt(disc)) / 2.0f * a;
	hit->t2 = (-b + sqrt(disc)) / 2.0f * a;
	s->hitpoint = tuple_add(sphere_to_ray, multiplyy(ray->dir, hit->t1));
	normal = tuple_normalize(s->hitpoint);
	lightdir = tuple_normalize(world->light->pos);
	double d = max(tuple_dot(normal, tuple_negate(lightdir)), 0.0f);
	s->material->color = multiplyy(s->material->color, d);
	return (hit);
}