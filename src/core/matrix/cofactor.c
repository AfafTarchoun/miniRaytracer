/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:10:04 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "matrix.h"
#include "utils.h"

double	matrix_cofactor_3(double **m, int row, int col)
{
	double	minor;

	minor = matrix_minor_3(m, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	return (-minor);
}

double	matrix_cofactor_4(double **m, int row, int col)
{
	double	**m1;
	double	det;

	m1 = matrix_sub_4(m, row, col);
	det = matrix_determinant_3(m1);
	matrix_free_3(m1);
	if ((row + col) % 2 == 0)
		return (det);
	return (-det);
}
