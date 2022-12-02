/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:44:00 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/01 21:35:16 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing/parser.h"

t_hit *cylinder_intersection(t_cylinder *cy, t_ray *ray, int x, int y)
{
    t_vector *cy_to_ray;
	double     a;
	double    b;
	double     c;
	double t;
	t_hit *hit;

	hit = ft_calloc(1, sizeof(t_hit));
    ray = ray_transform(ray, matrix_invert_4(cy->transform), NULL, matrix_free_4);
	cy_to_ray = tuple_sub(ray->origin, cy->origin);
	a = tuple_dot(ray->dir, ray->dir)
			- pow((tuple_dot(ray->dir, cy->orient)), 2);
	b = 2.0 * (tuple_dot(ray->dir, cy_to_ray) - tuple_dot(ray->dir,
					cy->orient) * tuple_dot(cy_to_ray, cyr->orient));
	c = tuple_dot(cy_to_ray, cy_to_ray) - pow(tuple_dot(cy_to_ray ,cy->orient), 2)
			- pow((cy->diameter / 2), 2);
	if ((b * b - 4 * a * c) < 0)
		return (NULL);
	world = ft_calloc(1, sizeof(t_hit));
	if (NOT hit)
		return (NULL);
	hit->t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	hit->t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (hit->t1 > hit->t2)
		t = hit->t2;
    else t = hit->t1;
	double z = ray->origin.y + ray->dir.y * t;
	if (z > cy->height || z < 0)
	{
		free(hit);
		return (NULL);
	}
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = CYLINDER;
	hit->entity->obj = cylinder;
	hit->x = x;
	hit->y = y;
	return (hit);
}