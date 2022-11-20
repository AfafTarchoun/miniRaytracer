/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:27:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/10/03 11:45:59 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_H
#define CREATE_H

#include "types.h"

t_shape *ambient_light_create(t_vec3 *color_nullable, double ratio, void (*f_nullable)(void *));
t_shape *ambient_light_from_line(char *line);
t_shape *camera_create(t_vec3 *coordinates, t_vec3 *orientation, double fov);
t_shape *camera_from_line(char *line);
t_shape *cylinder_create(t_vec3 *coordinates, t_vec3 *orientation, double diameter, double height, t_vec3 *color);
t_shape *cylinder_from_line(char *line);
t_shape *light_create(t_vec3 *coordinates, double brightness);
t_shape *light_from_line(char *line);
t_shape *plane_create(t_vec3 *coordinates, t_vec3 *orientation, t_vec3 *color);
t_shape *plane_from_line(char *line);
t_shape *sphere_create(t_vec3 *center, double diameter, t_vec3 *color);
t_shape *sphere_from_line(char *line);
#endif
