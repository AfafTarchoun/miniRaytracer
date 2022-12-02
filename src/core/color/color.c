/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/16 15:30:11 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color *color_create(float red, float green, float blue)
{
	t_color *color;

	color = ft_calloc(1, sizeof(t_color));
	color->x = red;
	color->y = green;
	color->z = blue;
	color->w = 2;
	return (color);
}
