/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:13:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 20:37:07 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "defs.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>
t_camera *camera(int w_size, int h_size, float fov)
{
	t_camera *c;
	float     half_v;
	float     aspect;

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
	aspect = (float) h_size / (float) w_size;
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
	return (c);
}
