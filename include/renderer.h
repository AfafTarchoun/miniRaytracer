/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:36:32 by habouiba          #+#    #+#             */
/*   Updated: 2022/10/06 07:41:32 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
#define RENDERER_H

#include "types.h"

void    render(t_vue *vue, t_scene *scene);
double  distance_between_camera_and_plane(t_camera_attr *camera);
t_vec3 *top_left_corner(t_camera_attr *camera);
#endif
