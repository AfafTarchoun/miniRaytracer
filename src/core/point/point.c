/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:59:15 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/15 18:01:01 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "tuple.h"

t_point *point_create(float x, float y, float z)
{
	t_point *p;

	p = tuple_create(x, y, z, 1);
	return (p);
}
