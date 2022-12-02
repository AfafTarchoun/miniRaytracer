/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:38:03 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/15 17:42:57 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "tuple.h"

t_vector *vector_create(float x, float y, float z)
{
	t_vector *vec;

	vec = tuple_create(x, y, z, 0);
	return (vec);
}
