/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:36:26 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

double	**matrix_rotate_x_4(double angle)
{
	double	**rotation;

	rotation = matrix_identity_4();
	rotation[1][1] = cos(angle);
	rotation[1][2] = -sin(angle);
	rotation[2][1] = sin(angle);
	rotation[2][2] = cos(angle);
	return (rotation);
}

double	**matrix_rotate_y_4(double angle)
{
	double	**rotation;

	rotation = matrix_identity_4();
	rotation[0][0] = cos(angle);
	rotation[0][2] = sin(angle);
	rotation[2][0] = -sin(angle);
	rotation[2][2] = cos(angle);
	return (rotation);
}

double	**matrix_rotate_z_4(double angle)
{
	double	**rotation;

	rotation = matrix_identity_4();
	rotation[0][0] = cos(angle);
	rotation[1][0] = sin(angle);
	rotation[0][1] = -sin(angle);
	rotation[1][1] = cos(angle);
	return (rotation);
}
