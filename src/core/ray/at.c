/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:15:12 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "ray.h"
#include "tuple.h"

t_point	*ray_at(t_ray *ray, double t)
{
	t_point	*scaled;
	t_point	*p;

	scaled = tuple_scale(ray->dir, t);
	p = tuple_add(ray->origin, scaled);
	free(scaled);
	return (p);
}
