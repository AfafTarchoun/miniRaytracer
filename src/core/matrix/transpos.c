/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:33:09 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	**matrix_transpos_n(double **_m, int n, void (*f)(void *))
{
	double	**m;
	int		i;
	int		j;

	m = matrix_create_4();
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			m[i][j] = _m[j][i];
			j++;
		}
		i++;
	}
	if (f)
		f(_m);
	return (m);
}

double	**matrix_transpos_4(double **_m, void (*f)(void *))
{
	return (matrix_transpos_n(_m, 4, f));
}

double	**matrix_transpos_3(double **_m, void (*f)(void *))
{
	return (matrix_transpos_n(_m, 3, f));
}

double	**matrix_transpos_2(double **_m, void (*f)(void *))
{
	return (matrix_transpos_n(_m, 2, f));
}
