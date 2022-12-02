/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:58:13 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/16 14:03:37 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple *tuple_normalize(t_tuple *t)
{
	t_tuple *t_norm;
	float    length;

	length = tuple_length(t);
	t_norm = tuple_create(t->x / length, t->y / length, t->z / length, t->w / length);
	return (t_norm);
}

t_tuple *tuple_normalize_f(t_tuple *t, void (*f)(void *))
{
	t_tuple *t_norm;
	float    length;

	length = tuple_length(t);
	t_norm = tuple_create(t->x / length, t->y / length, t->z / length, t->w / length);
	if (f)
		f(t);
	return (t_norm);
}
