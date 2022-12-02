/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:29:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 16:47:29 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float matrix_determinant_2(float **_m)
{
	return ((_m[0][0] * _m[1][1]) - (_m[0][1] * _m[1][0]));
}

float matrix_determinant_3(float **_m)
{
	float cof1;
	float cof2;
	float cof3;

	cof1 = matrix_cofactor_3(_m, 0, 0);
	cof2 = matrix_cofactor_3(_m, 0, 1);
	cof3 = matrix_cofactor_3(_m, 0, 2);
	return ((_m[0][0] * cof1) + (_m[0][1] * cof2) + (_m[0][2] * cof3));
}

float matrix_determinant_4(float **_m)
{
	float cof1;
	float cof2;
	float cof3;
	float cof4;

	cof1 = matrix_cofactor_4(_m, 0, 0);
	cof2 = matrix_cofactor_4(_m, 0, 1);
	cof3 = matrix_cofactor_4(_m, 0, 2);
	cof4 = matrix_cofactor_4(_m, 0, 3);
	return (_m[0][0] * cof1 + _m[0][1] * cof2 + _m[0][2] * cof3 + _m[0][3] * cof4);
}
