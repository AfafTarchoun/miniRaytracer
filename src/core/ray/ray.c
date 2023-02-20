/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:08:07 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/03 17:34:46 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "point.h"
#include "vector.h"

t_ray	*ray(t_point *origin, t_vector *dir)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!origin)
		origin = point_create(0, 0, 0);
	if (!dir)
		dir = vector_create(0, 0, 0);
	ray->origin = origin;
	ray->dir = dir;
	return (ray);
}
