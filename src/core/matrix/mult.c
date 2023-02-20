/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:14:30 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include <stdio.h>

double	__dot_product4(t_tuple *t1, t_tuple *t2,
	void (*f1)(void *), void (*f2)(void *))
{
	double	res;

	res = (t1->x * t2->x) + (t1->y * t2->y) + (t1->z * t2->z) + (t1->w * t2->w);
	if (f1)
		f1(t1);
	if (f2)
		f2(t2);
	return (res);
}

void	__matrix_mul_4_helper_1(double **m1, double **m2, double **m)
{
	m[0][0] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]),
			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[0][1] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]),
			tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[0][2] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]),
			tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[0][3] = __dot_product4(
			tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]),
			tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
	m[1][0] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]),
			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[1][1] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]),
			tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[1][2] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]),
			tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[1][3] = __dot_product4(
			tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]),
			tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
}

void	__matrix_mul_4_helper_2(double **m1, double **m2, double **m)
{
	m[2][0] = __dot_product4(
			tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]),
			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[2][1] = __dot_product4(
			tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]),
			tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[2][2] = __dot_product4(
			tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]),
			tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[2][3] = __dot_product4(
			tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]),
			tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
	m[3][0] = __dot_product4(
			tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]),
			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
	m[3][1] = __dot_product4(
			tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]),
			tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
	m[3][2] = __dot_product4(
			tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]),
			tuple_create(m2[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
	m[3][3] = __dot_product4(
			tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]),
			tuple_create(m2[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
}

double	**matrix_mul_4(double **m1, double **m2)
{
	double	**m;

	m = matrix_create_4();
	__matrix_mul_4_helper_1(m1, m2, m);
	__matrix_mul_4_helper_2(m1, m2, m);
	return (m);
}

// double	**matrix_mul_3(double **m1, double **m2)
// {
// 	double	**m;

// 	m = matrix_create_3();
// 	m[0][0] = __dot_product4(
// 			tuple_create(m1[0][0], m1[0][1], m1[0][2], 0),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], 0), free, free);
// 	m[0][1] = __dot_product4(
// 			tuple_create(m1[0][0], m1[0][1], m1[0][2], 0),
// 			tuple_create(m2[0][1], m2[1][1], m2[2][1], 0), free, free);
// 	m[0][2] = __dot_product4(tuple_create(m1[0][0], m1[0][1], m1[0][2], 0),
// 			tuple_create(m2[0][2], m2[1][2], m2[2][2], 0), free, free);

// 	m[1][0] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], 0),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], 0), free, free);
// 	m[1][1] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], 0),
// 			tuple_create(m2[0][1], m2[1][1], m2[2][1], 0), free, free);
// 	m[1][2] = __dot_product4(tuple_create(m1[1][0], m1[1][1], m1[1][2], 0),
// 			tuple_create(m2[0][2], m2[1][2], m2[2][2], 0), free, free);

// 	m[2][0] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], 0),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], 0), free, free);
// 	m[2][1] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], 0),
// 			tuple_create(m2[0][1], m2[1][1], m2[2][1], 0), free, free);
// 	m[2][2] = __dot_product4(tuple_create(m1[2][0], m1[2][1], m1[2][2], 0),
// 			tuple_create(m2[0][2], m2[1][2], m2[2][2], 0), free, free);
// 	return (m);
// }
