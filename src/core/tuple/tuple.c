/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:24:51 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/15 17:41:38 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple *tuple_create(float x, float y, float z, float w)
{
	t_tuple *tuple;

	tuple = ft_calloc(1, sizeof(t_tuple));
	if (!tuple)
		return (tuple);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}
