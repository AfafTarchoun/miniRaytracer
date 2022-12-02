/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:15:12 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/21 12:33:03 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "ray.h"
#include "tuple.h"

t_point *ray_at(t_ray *ray, float t)
{
	t_point *scaled;
	t_point *p;

	scaled = tuple_scale(ray->dir, t);
	p = tuple_add(ray->origin, scaled);
	free(scaled);
	return (p);
}
