/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera-to-plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:51:57 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 17:57:04 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "math.h"
#include "renderer.h"

double distance_between_camera_and_plane(t_camera_attr *camera)
{
	return (((double) VUE_HEIGHT / 2) / (tan((camera->fov / 2) * M_PI / 180)));
}
