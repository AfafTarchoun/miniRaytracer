/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:05:34 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

t_ray	*ray(t_point *origin, t_vector *dir);
void	ray_delete(void *_ray);
t_point	*ray_at(t_ray *ray, double t);
t_ray	*ray_transform(t_ray *r, double **transform,
			void (*f_ray)(void *), void (*f_tra)(void *));
void	ray_print(t_ray *ray);
t_ray	*ray_at_px(t_camera *c, int px, int py);
#endif // !DEBUG
