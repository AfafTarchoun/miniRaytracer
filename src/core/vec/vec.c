/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:17:25 by habouiba          #+#    #+#             */
/*   Updated: 2022/09/20 13:58:05 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "libft.h"
#include <stdio.h>
// #define vec3_create_empty() vec3_create(0, 0, 0) /* fuck norm */

t_vec3 *vec3_create(double x, double y, double z)
{
	t_vec3 *new;

	new = ft_calloc(1, sizeof(t_vec3));
	if (NOT new)
	{
		ft_putstr_fd(ALLOCATION_FAILURE, 2);
		return (NULL);
	}
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

double vec3_length(t_vec3 *vec)
{
	if (NOT vec)
		return (-1);
	return (sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
}

void vec3_unit_vector(t_vec3 *vec)
{
	t_vec3 *tmp;

	tmp = vec3_scale(vec, 1 / vec3_length(vec), NULL);
	vec->x = tmp->x;
	vec->y = tmp->y;
	vec->z = tmp->z;
	free(tmp);
}

void vec3_print(t_vec3 *vec)
{
	printf("\n--------------- vec3 ---------------\n");
	if (NOT vec)
	{
		printf("the vector is NULL\n");
		return;
	}
	printf("x --> %f\n", vec->x);
	printf("y --> %f\n", vec->y);
	printf("z --> %f\n", vec->z);
	printf("\n-------------------------------\n");
}

t_vec3 *vec3_create_empty()
{
	return (vec3_create(0, 0, 0));
}
