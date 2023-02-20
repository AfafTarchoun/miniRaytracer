/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_intersections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:53:42 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:46:58 by habouiba         ###   ########.fr       */
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

void	put_intersections_plane(t_hit *hit, t_image *image,
			int h, int w, t_world *world)
{
	t_plane		*plane;
	t_color		*c;

	if (hit->entity->type == PLANE)
	{
		plane = hit->entity->obj;
		if (!hit->hitpoint)
			return ;
		c = lighting(plane->material, world, hit,
				is_shadowed(world, hit->hitpoint));
		image_put_pixel(image, w, h, c);
		free(c);
	}
}

void	put_intersections_sphere(t_hit *hit, t_image *image,
			int h, int w, t_world *world)
{
	t_sphere	*sphere;
	t_color		*c;

	if (hit->entity->type == SPHERE)
	{
		sphere = hit->entity->obj;
		if (!hit->hitpoint)
			return ;
		c = lighting(sphere->material, world, hit,
				is_shadowed(world, hit->hitpoint));
		image_put_pixel(image, w, h, c);
		free(c);
	}
}

void	put_intersections_cylinder(t_hit *hit, t_image *image,
			int h, int w, t_world *world)
{
	t_cylinder		*cylinder;
	t_color			*c;

	if (hit->entity->type == CYLINDER)
	{
		cylinder = hit->entity->obj;
		if (!hit->hitpoint)
			return ;
		c = lighting(cylinder->material, world, hit,
				0);
		image_put_pixel(image, w, h, c);
		free(c);
	}
}

void	put_intersections(t_hit *hit, t_image *image,
			int h, int w, t_world *world)
{
	put_intersections_plane(hit, image, h, w, world);
	put_intersections_sphere(hit, image, h, w, world);
	put_intersections_cylinder(hit, image, h, w, world);
}
