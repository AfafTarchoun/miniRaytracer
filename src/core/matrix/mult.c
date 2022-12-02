/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:14:30 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 21:16:09 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include <stdio.h>

static float __dot_product4(t_tuple *t1, t_tuple *t2, void (*f1)(void *), void (*f2)(void *))
{
	float res;

	res = (t1->x * t2->x) + (t1->y * t2->y) + (t1->z * t2->z) + (t1->w * t2->w);
	if (f1)
		f1(t1);
	if (f2)
		f2(t2);
	return (res);
}

float **matrix_mul_4(float **m1, float **m2)
{
	float **m;

	m = matrix_create_4();
	m[0][0] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[0][1] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[0][2] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[0][3] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	m[1][0] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[1][1] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[1][2] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[1][3] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	m[2][0] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[2][1] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[2][2] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[2][3] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	m[3][0] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[3][1] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[3][2] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[3][3] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	return (m);
}

float **matrix_mul_4_f(float **m1, float **m2, void (*f1)(void *), void (*f2)(void *))
{
	float **m;

	m = matrix_create_4();
	m[0][0] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[0][1] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[0][2] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[0][3] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	m[1][0] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[1][1] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[1][2] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[1][3] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	m[2][0] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[2][1] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[2][2] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[2][3] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	m[3][0] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[3][1] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[3][2] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[3][3] = __dot_product4(tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);

	if (f1)
		f1(m1);
	if (f2)
		f2(m2);
	return (m);
}

float **matrix_mul_3(float **m1, float **m2)
{
	float **m;

	m = matrix_create_3();
	m[0][0] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], 0), tuple_create(m2[0][0], m2[1][0], m2[2][0], 0), free, free);
	m[0][1] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], 0), tuple_create(m2[0][1], m2[1][1], m2[2][1], 0), free, free);
	m[0][2] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], 0), tuple_create(m2[0][2], m2[1][2], m2[2][2], 0), free, free);

	m[1][0] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], 0), tuple_create(m2[0][0], m2[1][0], m2[2][0], 0), free, free);
	m[1][1] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], 0), tuple_create(m2[0][1], m2[1][1], m2[2][1], 0), free, free);
	m[1][2] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], 0), tuple_create(m2[0][2], m2[1][2], m2[2][2], 0), free, free);

	m[2][0] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], 0), tuple_create(m2[0][0], m2[1][0], m2[2][0], 0), free, free);
	m[2][1] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], 0), tuple_create(m2[0][1], m2[1][1], m2[2][1], 0), free, free);
	m[2][2] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], 0), tuple_create(m2[0][2], m2[1][2], m2[2][2], 0), free, free);

	return (m);
}

float **matrix_mul_2(float **m1, float **m2)
{
	float **m;

	m = matrix_create_2();
	m[0][0] = __dot_product4(tuple_create(m1[0][0], m1[0][1], 0, 0), tuple_create(m2[0][0], m2[1][0], 0, 0), free, free);
	m[0][1] = __dot_product4(tuple_create(m1[0][0], m1[0][1], 0, 0), tuple_create(m2[0][1], m2[1][1], 0, 0), free, free);
	m[0][2] = __dot_product4(tuple_create(m1[0][0], m1[0][1], 0, 0), tuple_create(m2[0][2], m2[1][2], 0, 0), free, free);

	m[1][0] = __dot_product4(tuple_create(m1[1][0], m1[1][1], 0, 0), tuple_create(m2[0][0], m2[1][0], 0, 0), free, free);
	m[1][1] = __dot_product4(tuple_create(m1[1][0], m1[1][1], 0, 0), tuple_create(m2[0][1], m2[1][1], 0, 0), free, free);
	m[1][2] = __dot_product4(tuple_create(m1[1][0], m1[1][1], 0, 0), tuple_create(m2[0][2], m2[1][2], 0, 0), free, free);

	return (m);
}

t_tuple *matrix_tuple_4(float **m, t_tuple *t, void (*f1)(void *), void (*f2)(void *))
{
	t_tuple *res;

	res = tuple_create(0, 0, 0, 0);
	res->x = __dot_product4(tuple_create(m[0][0], m[0][1], m[0][2], m[0][3]), t, free, NULL);
	res->y = __dot_product4(tuple_create(m[1][0], m[1][1], m[1][2], m[1][3]), t, free, NULL);
	res->z = __dot_product4(tuple_create(m[2][0], m[2][1], m[2][2], m[2][3]), t, free, NULL);
	res->w = __dot_product4(tuple_create(m[3][0], m[3][1], m[3][2], m[3][3]), t, free, NULL);
	if (f1)
		f1(m);
	if (f2)
		f2(t);
	return (res);
}

t_tuple *matrix_tuple_3(float **m, t_tuple *t, void (*f1)(void *), void (*f2)(void *))
{
	t_tuple *res;

	res = tuple_create(0, 0, 0, 0);
	res->x = __dot_product4(tuple_create(m[0][0], m[0][1], m[0][2], 0), t, free, NULL);
	res->y = __dot_product4(tuple_create(m[1][0], m[1][1], m[1][2], 0), t, free, NULL);
	res->z = __dot_product4(tuple_create(m[2][0], m[2][1], m[2][2], 0), t, free, NULL);
	res->w = t->w;
	if (f1)
		f1(m);
	if (f2)
		f2(t);
	return (res);
}

// t_tuple *matrix_tuple_2(float **m, t_tuple *t, void (*f1)(void *), void (*f2)(void *))
// {
// 	t_tuple *res;

// 	res = tuple_create(0, 0, 0, 0);
// 	res->x = __dot_product4(tuple_create(m[0][0], m[0][1], 0, 0), t, free,
// NULL); 	res->y = __dot_product4(tuple_create(m[1][0], m[1][1], 0, 0), t,
// free, NULL); 	res->z = __dot_product4(tuple_create(m[2][0], m[2][1], 0, 0),
// t, free, NULL); 	if (f1) 		f1(m); 	if (f2) 		f2(t); return (res);
// }
