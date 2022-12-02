/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:10:04 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 17:27:56 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "matrix.h"
#include "utils.h"

float matrix_cofactor_3(float **m, int row, int col)
{
	float minor;

	minor = matrix_minor_3(m, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	return (-minor);
}

float matrix_cofactor_4(float **m, int row, int col)
{
	float **m1;
	float   det;

	m1 = matrix_sub_4(m, row, col);
	det = matrix_determinant_3(m1);
	matrix_free_3(m1);
	if ((row + col) % 2 == 0)
		return (det);
	return (-det);
}
