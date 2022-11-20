/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec-arithmetic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:23:31 by habouiba          #+#    #+#             */
/*   Updated: 2022/10/07 17:15:10 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

t_vec3 *vec3_add(t_vec3 *vec1, t_vec3 *vec2, void (*f1_nullable)(void *), void (*f2_nullable)(void *))
{
	t_vec3 *new;

	if (NOT vec1 OR NOT vec2)
		return (vec1);
	new = ft_calloc(1, sizeof(t_vec3));
	if (NOT new)
	{
		ft_putstr_fd(ALLOCATION_FAILURE, 2);
		return (NULL);
	}
	new->x = vec1->x + vec2->x;
	new->y = vec1->y + vec2->y;
	new->z = vec1->z + vec2->z;
	if (f1_nullable)
		f1_nullable(vec1);
	if (f2_nullable)
		f2_nullable(vec2);
	return (new);
}

t_vec3 *vec3_sub(t_vec3 *vec1, t_vec3 *vec2, void (*f1_nullable)(void *), void (*f2_nullable)(void *))
{
	t_vec3 *new;

	if (NOT vec1 OR NOT vec2)
		return (vec1);
	new = ft_calloc(1, sizeof(t_vec3));
	if (NOT new)
	{
		ft_putstr_fd(ALLOCATION_FAILURE, 2);
		return (NULL);
	}
	new->x = vec1->x - vec2->x;
	new->y = vec1->y - vec2->y;
	new->z = vec1->z - vec2->z;
	if (f1_nullable)
		f1_nullable(vec1);
	if (f2_nullable)
		f2_nullable(vec2);
	return (new);
}

t_vec3 *vec3_scale(t_vec3 *vec, double scaler, void (*f_nullable)(void *))
{
	t_vec3 *new;

	if (NOT vec)
		return (vec);
	new = ft_calloc(1, sizeof(t_vec3));
	if (NOT new)
	{
		ft_putstr_fd(ALLOCATION_FAILURE, 2);
		return (NULL);
	}
	new->x = vec->x *scaler;
	new->y = vec->y *scaler;
	new->z = vec->z *scaler;
	if (f_nullable)
		f_nullable(vec);
	return (new);
}

t_vec3 *vec3_norm(t_vec3 *vec, void (*f)(void *))
{
	t_vec3 *norm_vec;

	if (NOT vec)
		return (NULL);
	norm_vec = vec3_create(vec->x / vec3_length(vec), vec->y / vec3_length(vec), vec->z / vec3_length(vec));
	if (f)
		f(vec);
	return (norm_vec);
}
