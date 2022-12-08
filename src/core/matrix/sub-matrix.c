/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub-matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:17:28 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/08 01:59:29 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float **matrix_sub_4(float **_m, int row, int col)
{
	float **m;
	int     i;
	int     j;
	int     k;
	int     l;

	m = matrix_create_3();
	i = 0;
	k = 0;
	while (i < 3)
	{
		j = 0;
		l = 0;
		if (k == row)
			k++;
		while (j < 3)
		{
			if (l == col)
				l++;
			m[i][j] = _m[k][l];
			j++;
			l++;
		}
		i++;
		k++;
	}
	return (m);
}

float **matrix_sub_3(float **_m, int row, int col)
{
	float **m;
	int     i;
	int     j;
	int     k;
	int     l;

	m = matrix_create_2();
	i = 0;
	k = 0;
	while (i < 2)
	{
		j = 0;
		l = 0;
		if (k == row)
			k++;
		while (j < 2)
		{
			if (l == col)
				l++;
			m[i][j] = _m[k][l];
			j++;
			l++;
		}
		i++;
		k++;
	}
	return (m);
}
