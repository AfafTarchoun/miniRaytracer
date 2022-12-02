/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:46:05 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 13:48:32 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void ray_print(t_ray *ray)
{
	if (!ray)
	{
		printf("%p\n", ray);
	}
	printf("ORIGIN: [%f, %f, %f] => DIR: [%f, %f, %f]\n", ray->origin->x,
	       ray->origin->y, ray->origin->z, ray->dir->x, ray->dir->y, ray->dir->z);
}
