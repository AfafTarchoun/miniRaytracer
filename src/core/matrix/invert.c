/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:57:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/24 15:44:41 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float **matrix_invert_4(float **m)
{
	float **invert_m;
	int     row;
	int     col;
	float   det;
	float   cofactor;

	if (matrix_is_invertable_n(m, 4) == false)
		return (NULL);
	det = matrix_determinant_4(m);
	invert_m = matrix_create_4();
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			cofactor = matrix_cofactor_4(m, row, col);
			invert_m[col][row] = cofactor / det;
			col++;
		}
		row++;
	}
	return (invert_m);
}
