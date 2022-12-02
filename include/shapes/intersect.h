/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:53:05 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/12 15:28:00 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "types.h"

t_intersection *sphere_intersection(t_sphere_attr *sphere, t_ray *ray, int x, int y);
t_intersection *plane_intersection(t_plane_attr *plane, t_ray *ray, int x, int y);
t_bool          cylinder_intersection(t_cylinder_attr *cylinder, t_ray *ray);
#endif
