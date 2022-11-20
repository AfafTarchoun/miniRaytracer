/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top-left-corner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:10:59 by habouiba          #+#    #+#             */
/*   Updated: 2022/10/07 17:19:37 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "ray.h"
#include "renderer.h"
#include "vec.h"

t_vec3 *top_left_corner(t_camera_attr *camera)
{
	t_vec3 *top_left;
	t_vec3 *tmp;
	t_vec3 *middle;

	middle = ray_point_at(ray_create(&camera->coordinates, &camera->orientation, NULL, NULL), distance_between_camera_and_plane(camera), free);
	tmp = vec3_create((double) VUE_WIDTH / 2, (double) VUE_HEIGHT / 2, 0);
	top_left = vec3_sub(middle, tmp, free, free);
	return (top_left);
}
