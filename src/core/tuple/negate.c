/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:22:17 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:41:45 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "types.h"

t_tuple	*tuple_negate(t_tuple *t)
{
	t_tuple	*n_t;

	if (!t)
		return (NULL);
	n_t = tuple_create(-t->x, -t->y, -t->z, -t->w);
	return (n_t);
}

t_tuple	*tuple_negate_f(t_tuple *t, void (*f)(void *))
{
	t_tuple	*n_t;

	if (!t)
		return (NULL);
	n_t = tuple_create(-t->x, -t->y, -t->z, -t->w);
	if (f)
		f(t);
	return (n_t);
}
