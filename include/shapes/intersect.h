/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:53:05 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:16:24 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "types.h"

t_intersection	*sphere_intersection(t_sphere_attr *sphere,
					t_ray *ray, int x, int y);
t_intersection	*plane_intersection(t_plane_attr *plane,
					t_ray *ray, int x, int y);
t_bool			cylinder_intersection(t_cylinder_attr *cylinder, t_ray *ray);
#endif
