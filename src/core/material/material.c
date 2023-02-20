/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:51:02 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:25:12 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "color.h"

t_material	*material(void)
{
	t_material	*m;

	m = ft_calloc(1, sizeof(t_material));
	m->color = color_create(1, 1, 1);
	m->ambient = 0.1f;
	m->deffuse = 0.9f;
	m->specular = 0.9f;
	m->shininess = 200.0f;
	return (m);
}
