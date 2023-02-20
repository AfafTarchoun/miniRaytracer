/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:01:07 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	**matrix_scale_4(t_tuple *t, void (*f)(void *))
{
	double	**scaling_m;

	scaling_m = matrix_identity_4();
	scaling_m[0][0] = t->x;
	scaling_m[1][1] = t->y;
	scaling_m[2][2] = t->z;
	if (f)
		f(t);
	return (scaling_m);
}
