/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:28:14 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/04 05:46:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "entity.h"
#include "world.h"

void	world_delete(t_world *world)
{
	free(world->alight->material->color);
	free(world->alight->material);
	free(world->alight);
	camera_delete(world->camera);
	free(world->light->pos);
	free(world->light);
	ft_lstclear(&world->objs, entity_delete);
	free(world);
}
