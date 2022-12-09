/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:52:51 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/09 07:12:04 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing/parser.h"

t_plane *plane(t_point *origin, t_material *m, t_point *orient)
{
	t_plane *pl;

	pl = ft_calloc(1, sizeof(t_plane));
	pl->origin = origin;
	pl->orient = orient;
	pl->transform = matrix_identity_4();
	pl->material = m;
	return (pl);
}

t_hit *hit_plane_create(float t1, float t2, t_plane *pl)
{
	t_hit *hit;

	hit = ft_calloc(1, sizeof(t_hit));
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = PLANE;
	hit->t1 = t1;
	hit->t2 = t2;
	if (pl)
		hit->entity->obj =
		    plane(point_create(pl->origin->x, pl->origin->y, pl->origin->z), material(),
                point_create(pl->orient->x, pl->orient->y, pl->orient->z));
	return (hit);
}

t_hit *ray_pl_hit(t_ray *ray,  t_plane *pl)
{
	double          denom;
	t_vector       *sub;
	double          t;
	t_hit           *hit;

	denom = tuple_dot(ray->dir, pl->orient);
	if (denom > 1e-6)
	{
		sub = tuple_sub(pl->origin, ray->origin);
		t = tuple_dot(sub, pl->orient) / denom;
		if (t < 0)
			return (NULL);
		hit = ft_calloc(1, sizeof(t_hit));
		hit->entity = ft_calloc(1, sizeof(t_entity));
		hit->entity->type = PLANE;
		hit->entity->obj = pl;
		hit->t1 = t;
		hit->t2 = t;
		return (hit);
	}
	return (NULL);
}