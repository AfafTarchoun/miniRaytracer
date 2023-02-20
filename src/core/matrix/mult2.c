/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:00 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"

double	**matrix_mul_2(double **m1, double **m2)
{
	double	**m;

	m = matrix_create_2();
	m[0][0] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], 0, 0),
			tuple_create(m2[0][0], m2[1][0], 0, 0), free, free);
	m[0][1] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], 0, 0),
			tuple_create(m2[0][1], m2[1][1], 0, 0), free, free);
	m[0][2] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], 0, 0),
			tuple_create(m2[0][2], m2[1][2], 0, 0), free, free);
	m[1][0] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], 0, 0),
			tuple_create(m2[0][0], m2[1][0], 0, 0), free, free);
	m[1][1] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], 0, 0),
			tuple_create(m2[0][1], m2[1][1], 0, 0), free, free);
	m[1][2] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], 0, 0),
			tuple_create(m2[0][2], m2[1][2], 0, 0), free, free);
	return (m);
}

t_tuple	*matrix_tuple_4(double **m, t_tuple *t,
	void (*f1)(void *), void (*f2)(void *))
{
	t_tuple	*res;

	res = tuple_create(0, 0, 0, 0);
	res->x = __dot_product4(
			tuple_create(m[0][0], m[0][1], m[0][2], m[0][3]), t, free, NULL);
	res->y = __dot_product4(
			tuple_create(m[1][0], m[1][1], m[1][2], m[1][3]), t, free, NULL);
	res->z = __dot_product4(
			tuple_create(m[2][0], m[2][1], m[2][2], m[2][3]), t, free, NULL);
	res->w = __dot_product4(
			tuple_create(m[3][0], m[3][1], m[3][2], m[3][3]), t, free, NULL);
	if (f1)
		f1(m);
	if (f2)
		f2(t);
	return (res);
}

t_tuple	*matrix_tuple_3(double **m, t_tuple *t,
	void (*f1)(void *), void (*f2)(void *))
{
	t_tuple	*res;

	res = tuple_create(0, 0, 0, 0);
	res->x = __dot_product4(
			tuple_create(m[0][0], m[0][1], m[0][2], 0), t, free, NULL);
	res->y = __dot_product4(
			tuple_create(m[1][0], m[1][1], m[1][2], 0), t, free, NULL);
	res->z = __dot_product4(
			tuple_create(m[2][0], m[2][1], m[2][2], 0), t, free, NULL);
	res->w = t->w;
	if (f1)
		f1(m);
	if (f2)
		f2(t);
	return (res);
}

double	**matrix_mul_4_f(double **m1, double **m2,
	void (*f1)(void *), void (*f2)(void *))
{
	double	**m;

	m = matrix_mul_4(m1, m2);
	if (f1)
		f1(m1);
	if (f2)
		f2(m2);
	return (m);
}
