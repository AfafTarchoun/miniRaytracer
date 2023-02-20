/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:52:51 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "defs.h"

void	plane_delete(void *_p)
{
	t_plane	*p;

	p = _p;
	free(p->origin);
	free(p->material->color);
	free(p->material);
	free(p->orient);
	matrix_free_4(p->transform);
	matrix_free_4(p->inv_transform);
	free(p);
}

t_hit	*hit_plane_create(double t1, double t2, t_plane *pl)
{
	t_hit	*hit;

	hit = ft_calloc(1, sizeof(t_hit));
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = PLANE;
	hit->t1 = t1;
	hit->t2 = t2;
	hit->entity->obj = pl;
	return (hit);
}

t_hit	*ray_pl_hit(t_ray *ray, t_plane *pl)
{
	double	t;
	t_hit	*hit;

	ray = ray_transform(ray, pl->inv_transform, NULL, NULL);
	if (fabs(ray->dir->y) < EPSILON)
	{
		ray_delete(ray);
		return (NULL);
	}
	t = -ray->origin->y / ray->dir->y;
	if (t < 0.00f)
	{
		ray_delete(ray);
		return (NULL);
	}
	hit = hit_plane_create(t, t, pl);
	hit->hitpoint = ray_at(ray, t);
	hit->eyev = tuple_negate(ray->dir);
	hit->norm = normal_at_plane(pl, hit->hitpoint, NULL);
	ray_delete(ray);
	return (hit);
}
