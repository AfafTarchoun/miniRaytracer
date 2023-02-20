/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:32:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:24:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	*hadamard_product(t_color *c1, t_color *c2)
{
	t_color	*color;

	color = color_create(c1->x * c2->x, c1->y * c2->y, c1->z * c2->z);
	return (color);
}

t_color	*hadamard_product_f(t_color *c1, t_color *c2,
	void (*f1)(void *), void (*f2)(void *))
{
	t_color	*color;

	color = color_create(c1->x * c2->x, c1->y * c2->y, c1->z * c2->z);
	if (f1)
		f1(c1);
	if (f2)
		f2(c2);
	return (color);
}
