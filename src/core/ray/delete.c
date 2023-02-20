/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:12:47 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:38:12 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_delete(void *_ray)
{
	t_ray	*ray;

	if (!_ray)
		return ;
	ray = _ray;
	free(ray->dir);
	free(ray->origin);
	free(_ray);
}
