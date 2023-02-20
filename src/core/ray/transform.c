/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:01:35 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "point.h"
#include "ray.h"
#include "vector.h"
#include <stdio.h>

t_ray	*ray_transform(t_ray *r, double **transform,
			void (*f_ray)(void *), void (*f_tra)(void *))
{
	t_ray	*new_ray;

	new_ray = ray(0, 0);
	free(new_ray->origin);
	free(new_ray->dir);
	new_ray->origin = matrix_tuple_4(transform, r->origin, 0, NULL);
	new_ray->dir = matrix_tuple_4(transform, r->dir, 0, NULL);
	if (f_ray)
		f_ray(r);
	if (f_tra)
		f_tra(transform);
	return (new_ray);
}
