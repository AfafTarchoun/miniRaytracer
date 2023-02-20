/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:58:16 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_minor_3(double **m, int row, int col)
{
	double	**sub;
	double	minor;

	sub = matrix_sub_3(m, row, col);
	minor = matrix_determinant_2(sub);
	matrix_free_2(sub);
	return (minor);
}

double	matrix_minor4(double **m, int row, int col)
{
	double	**m1;
	double	minor;

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
