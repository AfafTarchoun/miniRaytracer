/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:14:49 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/05 15:36:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reflection.h"
#include "tuple.h"
#include "parsing/parser.h"

t_vector	*reflect(t_vector *in, t_vector *normal)
{
	t_vector	*ref;

	ref = tuple_scale(normal, 2.0f * tuple_dot(in, normal));
	ref = tuple_sub_f(in, ref, NULL, free);
	return (ref);
}

t_vector	*reflect_f(t_vector *in, t_vector *normal,
		void (*f1)(void *), void (*f2)(void *))
{
	t_vector	*ref;

	ref = tuple_scale(normal, 2.0f * tuple_dot(in, normal));
	ref = tuple_sub_f(in, ref, NULL, free);
	if (f1)
		f1(in);
	if (f2)
		f2(normal);
	return (ref);
}
