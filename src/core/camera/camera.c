/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:13:39 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "defs.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>

void	__camera__(t_camera *c, double aspect, double half_v)
{
	if (aspect >= 1.0f)
	{
		c->half_w = half_v;
		c->half_h = half_v / aspect;
	}
	else
	{
		c->half_w = half_v * aspect;
		c->half_h = half_v;
	}
	c->psize = (c->half_w * 2) / c->hsize;
	c->transform = matrix_identity_4();
}

t_camera	*camera(int w_size, int h_size, double fov)
{
	t_camera	*c;
	double		half_v;
	double		aspect;

	c = ft_calloc(1, sizeof(t_camera));
	c->hsize = VUE_HEIGHT;
	if (h_size)
		c->hsize = h_size;
	c->wsize = VUE_WIDTH;
	if (w_size)
		c->wsize = w_size;
	c->fov = fov;
	c->transform = 0;
	half_v = tan(fov / 2.0f);
	aspect = (double)w_size / h_size;
	__camera__(c, aspect, half_v);
	return (c);
}
