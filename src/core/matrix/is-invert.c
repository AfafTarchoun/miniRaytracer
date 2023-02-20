/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is-invert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:44:25 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_bool	matrix_is_invertable_n(double **m, int n)
{
	double	det;

	det = 0;
	if (n == 4)
		det = matrix_determinant_4(m);
	else if (n == 3)
		det = matrix_determinant_3(m);
	else if (n == 2)
		det = matrix_determinant_2(m);
	if (det == 0)
		return (false);
	return (true);
}

t_bool	matrix_is_invertable_4(double **m)
{
	return (matrix_is_invertable_n(m, 4));
}

t_bool	matrix_is_invertable_3(double **m)
{
	return (matrix_is_invertable_n(m, 3));
}

t_bool	matrix_is_invertable_2(double **m)
{
	return (matrix_is_invertable_n(m, 2));
}
