/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is-invert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:44:25 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 13:12:42 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_bool matrix_is_invertable_n(float **m, int n)
{
	float det;

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

t_bool matrix_is_invertable_4(float **m)
{
	return (matrix_is_invertable_n(m, 4));
}

t_bool matrix_is_invertable_3(float **m)
{
	return (matrix_is_invertable_n(m, 3));
}

t_bool matrix_is_invertable_2(float **m)
{
	return (matrix_is_invertable_n(m, 2));
}
