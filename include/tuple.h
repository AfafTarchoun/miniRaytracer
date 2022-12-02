/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:31:53 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/24 13:54:29 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
#define TUPLES_H
#include "types.h"

t_tuple *tuple_create(float x, float y, float z, float w);
t_tuple *tuple_add(t_tuple *t1, t_tuple *t2);
t_tuple *tuple_scale(t_tuple *t, float denominator);
t_tuple *tuple_scale_f(t_tuple *t, float denominator, void (*f)(void *));
t_tuple *tuple_negate(t_tuple *t);
t_tuple *tuple_negate_f(t_tuple *t, void (*f)(void *));
float    tuple_length(t_tuple *t);
t_tuple *tuple_normalize(t_tuple *t);
t_tuple *tuple_normalize_f(t_tuple *t, void (*f)(void *));
t_tuple *tuple_scale(t_tuple *t, float scalar);
t_tuple *tuple_scale_f(t_tuple *t, float scalar, void (*f)(void *));
t_tuple *tuple_sub(t_tuple *t1, t_tuple *t2);
t_tuple *tuple_sub_f(t_tuple *t1, t_tuple *t2, void (*f1)(void *), void (*f2)(void *));
float    tuple_dot(t_tuple *t1, t_tuple *t2);
t_tuple *tuple_cross(t_tuple *t1, t_tuple *t2);
t_tuple *tuple_cross_f(t_tuple *t1, t_tuple *t2, void (*f1)(void *), void (*f2)(void *));
#endif
