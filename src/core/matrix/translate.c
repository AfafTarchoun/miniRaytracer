/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:09:41 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

double	**matrix_translate_creat_4(t_tuple *t, void (*f)(void *))
{
	double	**translate;

	translate = matrix_identity_4();
	translate[0][3] = t->x;
	translate[1][3] = t->y;
	translate[2][3] = t->z;
	if (f)
		f(t);
	return (translate);
}
