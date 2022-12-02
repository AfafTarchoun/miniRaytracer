/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:15:14 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/16 11:28:38 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "utils.h"

static float absf(float n)
{
	if (n > 0.0f)
		return (n);
	return (-n);
}

t_bool float_cmp(float a, float b)
{
	if (absf(a - b) < EPSILON)
		return (true);
	return (false);
}
