/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:29:38 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_determinant_2(double **_m)
{
	return ((_m[0][0] * _m[1][1]) - (_m[0][1] * _m[1][0]));
}

double	matrix_determinant_3(double **_m)
{
	double	cof1;
	double	cof2;
	double	cof3;

	cof1 = matrix_cofactor_3(_m, 0, 0);
	cof2 = matrix_cofactor_3(_m, 0, 1);
	cof3 = matrix_cofactor_3(_m, 0, 2);
	return ((_m[0][0] * cof1) + (_m[0][1] * cof2) + (_m[0][2] * cof3));
}

double	matrix_determinant_4(double **_m)
{
	double	cof1;
	double	cof2;
	double	cof3;
	double	cof4;

	cof1 = matrix_cofactor_4(_m, 0, 0);
	cof2 = matrix_cofactor_4(_m, 0, 1);
	cof3 = matrix_cofactor_4(_m, 0, 2);
	cof4 = matrix_cofactor_4(_m, 0, 3);
	return (_m[0][0] * cof1 + _m[0][1] * cof2 + _m[0][2]
			* cof3 + _m[0][3] * cof4);
}
