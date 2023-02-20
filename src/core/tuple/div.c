/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:50:24 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tuple.h"

t_tuple	*tuple_div(t_tuple *t, double denominator)
{
	t_tuple	*s_t;

	s_t = tuple_create(t->x / denominator, t->y / denominator,
			t->z / denominator, t->w / denominator);
	return (s_t);
}

t_tuple	*tuple_div_f(t_tuple *t, double denominator, void (*f)(void *))
{
	t_tuple	*s_t;

	s_t = tuple_create(t->x / denominator, t->y / denominator,
			t->z / denominator, t->w / denominator);
	if (f)
		f(t);
	return (s_t);
}
