/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:57:26 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	**matrix_invert_4(double **m)
{
	double	**invert_m;
	int		row;
	int		col;
	double	det;
	double	cofactor;

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
