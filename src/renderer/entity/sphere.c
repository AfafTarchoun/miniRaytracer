/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:01:19 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "matrix.h"
#include "material.h"

t_sphere	*sphere(t_point *origin, t_material *m, double raduis)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->origin = origin;
	sphere->raduis = raduis;
	sphere->transform = matrix_identity_4();
	sphere->material = m;
	return (sphere);
}

void	sphere_delete(void *_s)
{
	t_sphere	*s;

	s = _s;
	free(s->material->color);
	free(s->material);
	free(s->coord);
	free(s->origin);
	matrix_free_4(s->inv_transform);
	matrix_free_4(s->transform);
	free(s);
}

void	sphere_set_transform(t_sphere *s, double **matrix, void (*f)(void *))
{
	if (f)
		if (s->transform)
			f(s->transform);
	s->transform = matrix;
}
