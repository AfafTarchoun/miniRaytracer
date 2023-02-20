/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:01 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "types.h"

t_hit	*hit_sphere_create(double t1, double t2, t_sphere *sphere);
t_hit	*ray_sphere_hit(t_ray *ray, t_sphere *s);
t_hit	*ray_cy_hit(t_ray *ray, t_cylinder *cy);
t_hit	*ray_pl_hit(t_ray *ray, t_plane *pl);
void	hit_delete(void *_hit);
void	hit_delete_2d_list(t_list ***hits, t_camera *c);
void	put_intersections(t_hit *hit, t_image *image,
			int h, int w, t_world *world);
t_hit	*hit(t_list *lst);
double	which_positive_and_low(double a, double b);
#endif // !HIT_H
