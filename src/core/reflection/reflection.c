/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:14:49 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 16:20:33 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reflection.h"
#include "tuple.h"

t_vector *reflect(t_vector *in, t_vector *normal)
{
	t_vector *ref;

	ref = tuple_scale(normal, 2.0f * tuple_dot(in, normal));
	ref = tuple_sub_f(in, ref, NULL, free);
	return ref;
}
