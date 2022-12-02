/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:58:16 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 16:47:41 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float matrix_minor_3(float **m, int row, int col)
{
	float **sub;
	float   minor;

	sub = matrix_sub_3(m, row, col);
	minor = matrix_determinant_2(sub);
	matrix_free_2(sub);
	return (minor);
}

float matrix_minor4(float **m, int row, int col)
{
	float **m1;
	float   minor;

	m1 = matrix_sub_3(m, row, col);
	minor = 0;
	minor += m[0][0] * matrix_determinant_2(m1);
	matrix_free_2(m1);
	m1 = matrix_sub_3(m, row, col + 1);
	minor -= m[0][1] * matrix_determinant_2(m1);
	matrix_free_2(m1);
	m1 = matrix_sub_3(m, row, col + 2);
	minor += m[0][2] * matrix_determinant_2(m1);
	matrix_free_2(m1);
	return (minor);
}
