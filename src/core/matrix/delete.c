/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:11:47 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 10:39:24 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void matrix_free_n(void *_m, int n)
{
	float **m;
	int     i;

	m = _m;
	i = 0;
	while (i < n)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

void matrix_free_4(void *_m)
{
	matrix_free_n(_m, 4);
}

void matrix_free_3(void *_m)
{
	matrix_free_n(_m, 3);
}

void matrix_free_2(void *_m)
{
	matrix_free_n(_m, 2);
}
