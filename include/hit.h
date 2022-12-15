/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:01 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/15 12:00:28 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
#define HIT_H

#include "types.h"

t_hit *hit_sphere_create(float t1, float t2, t_sphere *sphere);
t_hit *ray_sphere_hit(t_ray *ray, t_sphere *s, t_world *world);
void   hit_delete(t_hit *hit);
t_hit *hit(t_list *lst);

#endif // !HIT_H
