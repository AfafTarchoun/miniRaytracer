/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:31:53 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H
# include "types.h"

t_tuple	*tuple_create(double x, double y, double z, double w);
t_tuple	*tuple_add(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_add_f(t_tuple *t1, t_tuple *t2,
			void (*f1)(void *), void (*f2)(void *));
t_tuple	*tuple_scale(t_tuple *t, double denominator);
t_tuple	*tuple_scale_f(t_tuple *t, double denominator, void (*f)(void *));
t_tuple	*tuple_negate(t_tuple *t);
t_tuple	*tuple_negate_f(t_tuple *t, void (*f)(void *));
double	tuple_length(t_tuple *t);
t_tuple	*tuple_normalize(t_tuple *t);
t_tuple	*tuple_normalize_f(t_tuple *t, void (*f)(void *));
t_tuple	*tuple_scale(t_tuple *t, double scalar);
t_tuple	*tuple_scale_f(t_tuple *t, double scalar, void (*f)(void *));
t_tuple	*tuple_sub(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_sub_f(t_tuple *t1, t_tuple *t2,
			void (*f1)(void *), void (*f2)(void *));
double	tuple_dot(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_cross(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_cross_f(t_tuple *t1, t_tuple *t2,
			void (*f1)(void *), void (*f2)(void *));
t_tuple	*tuple_div(t_tuple *t, double denominator);
t_tuple	*tuple_div_f(t_tuple *t, double denominator, void (*f)(void *));

#endif
