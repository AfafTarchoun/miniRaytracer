/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:44:00 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/17 18:22:34 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing/parser.h"

t_cylinder	*cylinder(t_point *origin, t_point *orient, t_material *m, double diameter, double height)
{
	t_cylinder *cy;

	cy = ft_calloc(1, sizeof(t_sphere));
	cy->origin = origin;
	cy->orient = orient;
	cy->diameter = diameter;
	cy->height = height;
	cy->transform = matrix_identity_4();
	cy->material = m;
	return (cy);
}

t_hit *hit_cy_create(float t1, float t2, t_cylinder *cy)
{
	t_hit *hit;

	hit = ft_calloc(1, sizeof(t_hit));
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = CYLINDER;
	hit->t1 = t1;
	hit->t2 = t2;
	if (cy)
		hit->entity->obj =
		    cylinder(point_create(cy->origin->x, cy->origin->y, cy->origin->z),
				point_create(cy->orient->x, cy->orient->y, cy->orient->z),
				material(), cy->diameter, cy->height);
	return (hit);
}

t_hit *ray_cy_hit(t_ray *ray, t_cylinder *cy)
{
	t_hit *hit;
	t_vector *cy_to_ray;
	double a;
	double b;
	double c;
	double z;
	double t;

	print_tuple(ray->dir);
	ray = ray_transform(ray, matrix_invert_4(cy->transform), NULL, matrix_free_4);
	cy_to_ray = tuple_sub(ray->origin, cy->origin);
	a = tuple_dot(ray->dir, ray->dir)
			- pow((tuple_dot(ray->dir, cy->orient)), 2);
	b = 2.0 * (tuple_dot(ray->dir, cy_to_ray) - tuple_dot(ray->dir,
					cy->orient) * tuple_dot(cy_to_ray, cy->orient));
	c = tuple_dot(cy_to_ray, cy_to_ray) - pow(tuple_dot(cy_to_ray ,cy->orient), 2)
			- pow((cy->diameter / 2), 2);
	// free(cy_to_ray);
	// ray_delete(ray);
	if ((b * b - 4 * a * c) < 0)
		return (NULL);
	hit = hit_cy_create(0, 0, cy);
	hit->t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	hit->t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (hit->t1 > hit->t2)
		t = hit->t2;
    else t = hit->t1;
	z = ray->origin->y + ray->dir->y * t;
	if (z > cy->height || z < 0)
	{
		free(hit);
		return (NULL);
	}
	return (hit);
}