/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@43.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:56:03 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/12 14:29:27 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/renderer.h"
#include "../../include/color.h"
#include "../../include/defs.h"
#include "../../include/image.h"
#include "../../libs/libft/libft.h"
#include "mlx.h"
#include "../../include/ray.h"
#include "../../include/shapes/intersect.h"
#include "../../include/vec.h"
#include "../../include/vue.h"
#include <stdio.h>
#include <stdlib.h>

t_list *get_intersections(t_list *objs, t_ray *ray, int x, int y);
void    put_intersections(t_list *intersections, t_image *image);
void    render(t_vue *vue, t_scene *scene)
{
	t_ray    ray;
	int      i;
	int      j;
	t_image *image;
	t_vec3  *top_left;
	t_list  *intersections;

	i = 0;
	ray.origin.x = scene->camera->coordinates.x;
	ray.origin.y = scene->camera->coordinates.y;
	ray.origin.z = scene->camera->coordinates.z;
	printf("%lf\n", ray.origin.z);
	top_left = top_left_corner(scene->camera);
	image = image_init(vue);
	while (i < VUE_HEIGHT)
	{
		j = 0;
		while (j < VUE_WIDTH)
		{
			ray.direction.x = top_left->x + j;
			ray.direction.y = top_left->y + i;
			ray.direction.z = top_left->z;
			intersections = get_intersections(scene->objects, &ray, j, i);
			put_intersections(intersections, image);
			j++;
		}
		i++;
	}
	free(top_left);
	mlx_put_image_to_window(vue->mlx, vue->window, image->img, 0, 0);
}

t_list *get_intersections(t_list *objs, t_ray *ray, int x, int y)
{
	t_shape        *shape;
	t_list         *intersections;
	t_intersection *intersect;

	intersections = NULL;
	while (objs)
	{
		shape = objs->content;
		if (shape->type == SPHERE)
		{
			intersect = sphere_intersection(shape->attr, ray, x, y);
			if (intersect)
				ft_lstadd_back(&intersections, ft_lstnew(intersect));
		}
		else if (shape->type == PLANE)
		{
			intersect = plane_intersection(shape->attr, ray, x, y);
			if (intersect)
				ft_lstadd_back(&intersections, ft_lstnew(intersect));
		}
		else if (shape->type == CYLINDER)
		{
			intersect = cylinder_intersection(shape->attr, ray, x, y);
			if (intersect)
				ft_lstadd_back(&intersections, ft_lstnew(intersect));
		}
		objs = objs->next;
	}
	return (intersections);
}

// void log_inters(t_intersection *inter)
// {
// 	printf("inter %p\n", inter);
// 	printf("shape %p\n", inter->shape);
// 	if (inter->shape->type == PLANE)
// 		printf("type plane\n");
// 	if (inter->shape->type == SPHERE)
// 		printf("type sphere\n");
// 	printf("attr %p\n", inter->shape->attr);
// 	printf("x %i, y %i\n", inter->x, inter->y);
// }

void put_intersections(t_list *intersections, t_image *image)
{
	t_intersection *intersection;
	t_sphere_attr  *sphere;
	t_plane_attr   *plane;
	t_cylinder_attr *cylinder;

	// remove duplicate inters based on distance
	while (intersections)
	{
		intersection = intersections->content;
		if (intersection->shape->type == SPHERE)
		{
			sphere = intersection->shape->attr;
			image_put_pixel(
			    image, intersection->x, intersection->y,
			    create_trgb(0, sphere->color.x, sphere->color.y, sphere->color.z));
		}
		else if (intersection->shape->type == PLANE)
		{
			plane = intersection->shape->attr;
			image_put_pixel(
			    image, intersection->x, intersection->y,
			    create_trgb(0, plane->color.x, plane->color.y, plane->color.z));
		}
		else if (intersection->shape->type == CYLINDER)
		{
			cylinder = intersection->shape->attr;
			image_put_pixel(
			    image, intersection->x, intersection->y,
			    create_trgb(0, cylinder->color.x, cylinder->color.y, cylinder->color.z));
		}
		intersections = intersections->next;
	}
}
