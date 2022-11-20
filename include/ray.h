/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:25:02 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 02:48:16 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "types.h"
# include "vec.h"
# include "defs.h"

t_ray	*ray_create(t_vec3 *origin, t_vec3 *direction,
			void (*f1)(void *), void (*f2)(void *));
t_vec3	*ray_point_at(t_ray *ray, double t, void (*f)(void *));
void	vec3_unit_vector(t_vec3 *vec);
#endif
