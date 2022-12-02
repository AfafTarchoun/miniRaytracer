/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:50:24 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/21 12:29:55 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tuple.h"

t_tuple *tuple_div(t_tuple *t, float denominator)
{
	t_tuple *s_t;

	s_t = tuple_create(t->x / denominator, t->y / denominator, t->z / denominator, t->w / denominator);
	return (s_t);
}

t_tuple *tuple_div_f(t_tuple *t, float denominator, void (*f)(void *))
{
	t_tuple *s_t;

	s_t = tuple_create(t->x / denominator, t->y / denominator, t->z / denominator, t->w / denominator);
	if (f)
		f(t);
	return (s_t);
}
