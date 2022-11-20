/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:27:18 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 02:47:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
#define VEC_H
#include "defs.h"
#include "../libs/libft/libft.h"
#include "types.h"
#include <math.h>
#include <stdlib.h>

t_vec3 *vec3_create(double x, double y, double z);
t_vec3 *vec3_create_empty(void);
t_vec3 *vec3_add(t_vec3 *vec1, t_vec3 *vec2, void (*f1_nullable)(void *), void (*f2_nullable)(void *));
t_vec3 *vec3_sub(t_vec3 *vec1, t_vec3 *vec2, void (*f1_nullable)(void *), void (*f2_nullable)(void *));
t_vec3 *vec3_scale(t_vec3 *vec, double scaler, void (*f_nullable)(void *));
double  vec3_length(t_vec3 *vec);
double  vec3_dot_product(t_vec3 *vec1, t_vec3 *vec2);
t_vec3 *vec3_cross_product(t_vec3 *vec1, t_vec3 *vec2, void (*f1_nullable)(void *), void (*f2_nullable)(void *));
void    vec3_print(t_vec3 *vec);
t_vec3 *vec3_norm(t_vec3 *vec, void (*f)(void *));
t_vec3	ft_vec3_normalize(t_vec3 vec1);
double	ft_vec3_mag(t_vec3 *vec1);
t_ray  *calculate_ray(t_camera *camera, double u, double v); // make it static
#endif
