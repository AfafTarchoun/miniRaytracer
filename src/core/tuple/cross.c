/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:28:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:40:58 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	*tuple_cross(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*cross;

	cross = tuple_create(t1->y * t2->z - t1->z * t2->y,
			t1->z * t2->x - t1->x * t2->z,
			t1->x * t2->y - t1->y * t2->x, 0);
	return (cross);
}

t_tuple	*tuple_cross_f(t_tuple *t1, t_tuple *t2,
			void (*f1)(void *), void (*f2)(void *))
{
	t_tuple	*cross;

	cross = tuple_create(t1->y * t2->z - t1->z * t2->y,
			t1->z * t2->x - t1->x * t2->z,
			t1->x * t2->y - t1->y * t2->x, 0);
	if (f1)
		f1(t1);
	if (f2)
		f2(t2);
	return (cross);
}
