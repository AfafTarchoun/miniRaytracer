/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:01:46 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/16 17:08:36 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"

t_bool matrix_cmp(float **m1, float **m2, int len)
{
	int j;
	int i;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (float_cmp(m1[i][j], m2[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool matrix_cmp_4(float **m1, float **m2)
{
	return (matrix_cmp(m1, m2, 4));
}

t_bool matrix_cmp_3(float **m1, float **m2)
{
	return (matrix_cmp(m1, m2, 3));
}

t_bool matrix_cmp_2(float **m1, float **m2)
{
	return (matrix_cmp(m1, m2, 2));
}
