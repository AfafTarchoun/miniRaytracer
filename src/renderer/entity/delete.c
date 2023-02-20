/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:32:00 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/04 21:04:04 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

void	entity_delete(void *_e)
{
	t_entity	*e;

	e = _e;
	if (e->type == PLANE)
		plane_delete(e->obj);
	else if (e->type == SPHERE)
		sphere_delete(e->obj);
	else if (e->type == CYLINDER)
		cylinder_delete(e->obj);
	free(_e);
}
