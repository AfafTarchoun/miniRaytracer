/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:18:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/17 13:27:34 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes/intersect.h"
#include "vec.h"

t_intersection *cylinder_intersection(t_cylinder_attr *cylinder, t_ray *ray, int x, int y)
{
    t_vec3 *oc;
	int     a;
	int     b;
	int     c;
	double t;
	// double m;
	t_intersection *intersection;

	oc = vec3_sub(&ray->origin, &cylinder->coordinates, NULL, NULL);
	a = vec3_dot_product(&ray->direction, &ray->direction) 
			- pow((vec3_dot_product(&ray->direction, &cylinder->orientation)), 2);
	b = 2.0 * (vec3_dot_product(&ray->direction, oc) - vec3_dot_product(&ray->direction,
					&cylinder->orientation) * vec3_dot_product(oc, &cylinder->orientation));
	c = vec3_dot_product(oc, oc) - pow(vec3_dot_product(oc,&cylinder->orientation), 2)
			- (cylinder->diameter / 2) * (cylinder->diameter / 2);
	if ((b * b - 4 * a * c) < 0)
		return (NULL);
	intersection = ft_calloc(1, sizeof(t_intersection));
	if (NOT intersection)
		return (NULL);
	intersection->t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	intersection->t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (intersection->t1 > intersection->t2)
		t = intersection->t2;
    else t = intersection->t1;
	double z = ray->direction.z + ray->direction.z * t;
	if (z > 10)
	{
		free(intersection);
		return (NULL);
	}
	intersection->shape = ft_calloc(1, sizeof(t_shape));
	intersection->shape->type = CYLINDER;
	intersection->shape->attr = cylinder;
	intersection->x = x;
	intersection->y = y;
	return (intersection);
}
