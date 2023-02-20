/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub-matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:17:28 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	**matrix_sub_4(double **_m, int row, int col)
{
	double	**m;
	int		i;
	int		j;
	int		k;
	int		l;

	m = matrix_create_3();
	i = -1;
	k = 0;
	while (++i < 3)
	{
		j = -1;
		l = 0;
		if (k == row)
			k++;
		while (++j < 3)
		{
			if (l == col)
				l++;
			m[i][j] = _m[k][l];
			l++;
		}
		k++;
	}
	return (m);
}

double	**matrix_sub_3(double **_m, int row, int col)
{
	double	**m;
	int		i;
	int		j;
	int		k;
	int		l;

	m = matrix_create_2();
	i = -1;
	k = 0;
	while (++i < 2)
	{
		j = -1;
		l = 0;
		if (k == row)
			k++;
		while (++j < 2)
		{
			if (l == col)
				l++;
			m[i][j] = _m[k][l];
			l++;
		}
		k++;
	}
	return (m);
}
