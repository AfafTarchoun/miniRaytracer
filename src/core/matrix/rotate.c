/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:36:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/21 11:44:15 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

float **matrix_rotate_x_4(float angle)
{
	float **rotation;

	rotation = matrix_identity_4();
	rotation[1][1] = cos(angle);
	rotation[1][2] = -sin(angle);
	rotation[2][1] = sin(angle);
	rotation[2][2] = cos(angle);
	return rotation;
}

float **matrix_rotate_y_4(float angle)
{
	float **rotation;

	rotation = matrix_identity_4();
	rotation[0][0] = cos(angle);
	rotation[0][2] = sin(angle);
	rotation[2][0] = -sin(angle);
	rotation[2][2] = cos(angle);
	return rotation;
}

float **matrix_rotate_z_4(float angle)
{
	float **rotation;

	rotation = matrix_identity_4();
	rotation[0][0] = cos(angle);
	rotation[1][0] = sin(angle);
	rotation[0][1] = -sin(angle);
	rotation[1][1] = cos(angle);
	return rotation;
}
