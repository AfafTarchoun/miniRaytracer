/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:48:00 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 21:17:33 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float **matrix_create_4()
{
	float **matrix;
	int     i;

	matrix = ft_calloc(4, sizeof(float *));
	i = 0;
	while (i < 4)
	{
		matrix[i] = ft_calloc(4, sizeof(float));
		i++;
	}
	return (matrix);
}

float **matrix_create_3()
{
	float **matrix;
	int     i;

	matrix = ft_calloc(3, sizeof(float *));
	i = 0;
	while (i < 3)
	{
		matrix[i] = ft_calloc(3, sizeof(float));
		i++;
	}
	return (matrix);
};

float **matrix_create_2()
{
	float **matrix;
	int     i;

	matrix = ft_calloc(2, sizeof(float *));
	i = 0;
	while (i < 2)
	{
		matrix[i] = ft_calloc(2, sizeof(float));
		i++;
	}
	return (matrix);
};

float **matrix_identity_4(void)
{
	float **matrix;

	matrix = matrix_create_4();
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
	return (matrix);
}
