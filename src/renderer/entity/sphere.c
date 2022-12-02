/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:01:19 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 16:48:23 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "matrix.h"

t_sphere *sphere(t_point *origin, t_material *m, float raduis)
{
	t_sphere *sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->origin = origin;
	sphere->raduis = raduis;
	sphere->transform = matrix_identity_4();
	sphere->material = m;
	return (sphere);
}

void sphere_set_transform(t_sphere *s, float **matrix, void (*f)(void *))
{
	if (f)
		if (s->transform)
			f(s->transform);
	s->transform = matrix;
}
