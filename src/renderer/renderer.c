/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:35:56 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/05 19:54:05 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "parsing/parser.h"
#include "defs.h"
#include "hit.h"
#include "image.h"
#include "matrix.h"
#include "mlx.h"
#include "normals.h"
#include "point.h"
#include "ray.h"
#include "light.h"
#include <stdio.h>
#include "shadow.h"

// objs list of t_shape
t_list	*get_all_hits(t_list *objs, t_ray *ray)
{
	t_list		*hits;
	t_hit		*hit;
	t_entity	*entity;

	hits = NULL;
	while (objs)
	{
		hit = 0;
		entity = objs->content;
		if (entity->type == SPHERE)
			hit = ray_sphere_hit(ray, entity->obj);
		else if (entity->type == CYLINDER)
			hit = ray_cy_hit(ray, entity->obj);
		else if (entity->type == PLANE)
			hit = ray_pl_hit(ray, entity->obj);
		if (hit)
			ft_lstadd_back(&hits, ft_lstnew(hit));
		objs = objs->next;
	}
	return (hits);
}

t_image	*__render__(t_vue *vue, t_world *world, t_list ***hits)
{
	t_image	*image;
	int		h;
	int		w;
	t_hit	*closest_hit;

	h = -1;
	image = image_init(vue, world->camera);
	while (++h < world->camera->hsize)
	{
		w = 0;
		while (w < world->camera->wsize)
		{
			if (!hits[h][w])
			{
				w++;
				continue ;
			}
			closest_hit = hit(hits[h][w]);
			if (closest_hit)
				put_intersections(closest_hit, image, h, w, world);
			w++;
		}
	}
	hit_delete_2d_list(hits, world->camera);
	return (image);
}

t_image	*render(t_world *world, t_vue *vue)
{
	t_ray	*ray;
	int		h;
	int		w;
	t_list	***hits;

	h = 0;
	hits = ft_calloc(world->camera->hsize, sizeof(t_list **));
	while (h < world->camera->hsize)
	{
		w = 0;
		hits[h] = ft_calloc(world->camera->wsize, sizeof(t_list *));
		while (w < world->camera->wsize)
		{
			ray = ray_at_px(world->camera, w, h);
			hits[h][w] = get_all_hits(world->objs, ray);
			ray_delete(ray);
			w++;
		}
		h++;
	}
	return (__render__(vue, world, hits));
}
