/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:47:57 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"

// double	**matrix_mul_4_f(double **m1, double **m2,
// 	void (*f1)(void *), void (*f2)(void *))
// {
// 	double	**m;

// 	m = matrix_create_4();
// 	m[0][0] = __dot_product4(
// 			tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
// 	m[0][1] = __dot_product4(
// 			tuple_create(m1[0][0], m1[0][1], m1[0][2], m1[0][3]),
// 			tuple_create(m2[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
// 	m[0][2] = __dot_product4(tuple_create(m1
// 			[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m
// 			[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
// 	m[0][3] = __dot_product4(tuple_create(m1
// 			[0][0], m1[0][1], m1[0][2], m1[0][3]), tuple_create(m
// 			[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
// 	m[1][0] = __dot_product4(
// 			tuple_create(m1[1][0], m1[1][1], m1[1][2], m1[1][3]),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
// 	m[1][1] = __dot_product4(tuple_create(m1
// 			[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m
// 			[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
// 	m[1][2] = __dot_product4(tuple_create(m1
// 			[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m
// 			[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
// 	m[1][3] = __dot_product4(tuple_create(m1
// 			[1][0], m1[1][1], m1[1][2], m1[1][3]), tuple_create(m
// 			[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
// 	m[2][0] = __dot_product4(
// 			tuple_create(m1[2][0], m1[2][1], m1[2][2], m1[2][3]),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
// 	m[2][1] = __dot_product4(tuple_create(m1
// 			[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m
// 			[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
// 	m[2][2] = __dot_product4(tuple_create(m1
// 			[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m
// 			[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
// 	m[2][3] = __dot_product4(tuple_create(m1
// 			[2][0], m1[2][1], m1[2][2], m1[2][3]), tuple_create(m
// 			[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
// 	m[3][0] = __dot_product4(
// 			tuple_create(m1[3][0], m1[3][1], m1[3][2], m1[3][3]),
// 			tuple_create(m2[0][0], m2[1][0], m2[2][0], m2[3][0]), free, free);
// 	m[3][1] = __dot_product4(tuple_create(m1
// 			[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m
// 			[0][1], m2[1][1], m2[2][1], m2[3][1]), free, free);
// 	m[3][2] = __dot_product4(tuple_create(m1
// 			[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m
// 			[0][2], m2[1][2], m2[2][2], m2[3][2]), free, free);
// 	m[3][3] = __dot_product4(tuple_create(m1
// 			[3][0], m1[3][1], m1[3][2], m1[3][3]), tuple_create(m
// 			[0][3], m2[1][3], m2[2][3], m2[3][3]), free, free);
// 	if (f1)
// 		f1(m1);
// 	if (f2)
// 		f2(m2);
// 	return (m);
// }
