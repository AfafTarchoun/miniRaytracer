/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:01:36 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:42:41 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tuple.h"

t_tuple	*tuple_sub(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*t;

	if (!t1 || !t2)
		return (NULL);
	t = ft_calloc(1, sizeof(t_tuple));
	if (!t)
		return (t);
	t->x = t1->x - t2->x;
	t->y = t1->y - t2->y;
	t->z = t1->z - t2->z;
	t->w = t1->w - t2->w;
	return (t);
}

t_tuple	*tuple_sub_f(t_tuple *t1, t_tuple *t2,
			void (*f1)(void *), void (*f2)(void *))
{
	t_tuple	*t;

	if (!t1 || !t2)
		return (NULL);
	t = ft_calloc(1, sizeof(t_tuple));
	if (!t)
		return (t);
	t->x = t1->x - t2->x;
	t->y = t1->y - t2->y;
	t->z = t1->z - t2->z;
	t->w = t1->w - t2->w;
	if (f1)
		f1(t1);
	if (f2)
		f2(t2);
	return (t);
}
