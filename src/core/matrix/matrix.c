/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:48:00 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	**matrix_create_4(void)
{
	double	**matrix;
	int		i;

	matrix = ft_calloc(4, sizeof(double *));
	i = 0;
	while (i < 4)
	{
		matrix[i] = ft_calloc(4, sizeof(double));
		i++;
	}
	return (matrix);
}

double	**matrix_create_3(void)
{
	double	**matrix;
	int		i;

	matrix = ft_calloc(3, sizeof(double *));
	i = 0;
	while (i < 3)
	{
		matrix[i] = ft_calloc(3, sizeof(double));
		i++;
	}
	return (matrix);
}

double	**matrix_create_2(void)
{
	double	**matrix;
	int		i;

	matrix = ft_calloc(2, sizeof(double *));
	i = 0;
	while (i < 2)
	{
		matrix[i] = ft_calloc(2, sizeof(double));
		i++;
	}
	return (matrix);
}

double	**matrix_identity_4(void)
{
	double	**matrix;

	matrix = matrix_create_4();
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
	return (matrix);
}
