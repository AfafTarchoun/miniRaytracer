/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:28:10 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tuple.h"

t_tuple	*tuple_scale(t_tuple *t, double scalar)
{
	t_tuple	*s_t;

	s_t = tuple_create(t->x * scalar, t->y * scalar,
			t->z * scalar, t->w * scalar);
	return (s_t);
}

t_tuple	*tuple_scale_f(t_tuple *t, double scalar, void (*f)(void *))
{
	t_tuple	*s_t;

	s_t = tuple_create(t->x * scalar, t->y * scalar,
			t->z * scalar, t->w * scalar);
	if (f)
		f(t);
	return (s_t);
}
