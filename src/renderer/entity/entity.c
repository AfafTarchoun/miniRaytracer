/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:30:24 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:59:22 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

t_entity	*entity(t_entity_type type, void *obj)
{
	t_entity	*entity;

	entity = ft_calloc(1, sizeof(t_entity));
	entity->type = type;
	entity->obj = obj;
	return (entity);
}
