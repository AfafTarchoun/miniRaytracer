/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:01:46 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"

t_bool	matrix_cmp(double **m1, double **m2, int len)
{
	int	j;
	int	i;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (double_cmp(m1[i][j], m2[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	matrix_cmp_4(double **m1, double **m2)
{
	return (matrix_cmp(m1, m2, 4));
}

t_bool	matrix_cmp_3(double **m1, double **m2)
{
	return (matrix_cmp(m1, m2, 3));
}

t_bool	matrix_cmp_2(double **m1, double **m2)
{
	return (matrix_cmp(m1, m2, 2));
}
