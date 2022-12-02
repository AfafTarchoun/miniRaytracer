/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:33:09 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/18 15:46:18 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float **matrix_transpos_n(float **_m, int n, void (*f)(void *))
{
	float **m;
	int     i;
	int     j;

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

float **matrix_transpos_4(float **_m, void (*f)(void *))
{
	return (matrix_transpos_n(_m, 4, f));
}

float **matrix_transpos_3(float **_m, void (*f)(void *))
{
	return (matrix_transpos_n(_m, 3, f));
}

float **matrix_transpos_2(float **_m, void (*f)(void *))
{
	return (matrix_transpos_n(_m, 2, f));
}
