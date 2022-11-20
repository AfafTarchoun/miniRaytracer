/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec-products.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:51:46 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/17 11:02:43 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

double vec3_dot_product(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

double	ft_vec3_mag(t_vec3 *vec1)
{
	return (sqrt(vec1->x * vec1->x + vec1->y * vec1->y + vec1->z * vec1->z));
}

t_vec3	ft_vec3_normalize(t_vec3 vec1)
{
	t_vec3		ret;
	double		hold;

	hold = ft_vec3_mag(&vec1);
	if (hold == 0)
		return (vec1);
	ret.x = vec1.x / hold;
	ret.y = vec1.y / hold;
	ret.z = vec1.z / hold;
	return (ret);
}

t_vec3 *vec3_cross_product(t_vec3 *vec1, t_vec3 *vec2, void (*f1_nullable)(void *), void (*f2_nullable)(void *))
{
	t_vec3 *new;

	new = vec3_create(0, 0, 0);
	if (NOT new)
		return (NULL);
	new->x = vec1->y * vec2->z - vec1->z * vec2->y;
	new->y = vec1->z * vec2->x - vec1->x * vec2->z;
	new->x = vec1->x * vec2->y - vec1->y * vec2->x;
	if (f1_nullable)
		f1_nullable(vec1);
	if (f2_nullable)
		f2_nullable(vec2);
	return (new);
}
