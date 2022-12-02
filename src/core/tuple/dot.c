/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:11:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/21 16:07:59 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

float tuple_dot(t_tuple *t1, t_tuple *t2)
{
	float dot;

	dot = t1->x * t2->x + t1->y * t2->y + t1->z * t2->z + t1->w * t2->w;
	return (dot);
}
