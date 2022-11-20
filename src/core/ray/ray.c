/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:26:10 by habouiba          #+#    #+#             */
/*   Updated: 2022/10/07 17:19:01 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ray.h"
#include "stdio.h"

t_ray *ray_create(t_vec3 *origin, t_vec3 *direction, void (*f1)(void *), void (*f2)(void *))
{
	t_ray *ray;

	if (NOT origin)
		return (NULL);
	ray = ft_calloc(1, sizeof(t_ray));
	if (NOT ray)
	{
		perror("Error: ");
		return (NULL);
	}
	ray->origin.x = origin->x;
	ray->origin.y = origin->y;
	ray->origin.z = origin->z;
	ray->direction.x = direction->x;
	ray->direction.y = direction->y;
	ray->direction.z = direction->z;
	if (f1)
		free(origin);
	if (f2)
		free(direction);
	return (ray);
}

inline void ray_destroy(t_ray *ray)
{
	if (NOT ray)
		return;
	free(ray);
}

t_vec3 *ray_point_at(t_ray *ray, double t, void (*f)(void *))
{
	t_vec3 *vec;

	if (NOT ray)
		return (NULL);
	vec = vec3_scale(&ray->direction, t, NULL);
	if (NOT vec)
		return (NULL);
	vec = vec3_add(&ray->origin, vec, NULL, free);
	if (NOT vec)
	{
		free(vec);
		return (NULL);
	}
	if (f)
	{
		f(ray);
	}
	return (vec);
}
