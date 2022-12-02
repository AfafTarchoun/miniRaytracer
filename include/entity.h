/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 16:48:35 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
#define ENTITY_H

#include "types.h"

t_entity *entity(t_entity_type type, void *obj);
t_sphere *sphere(t_point *origin, t_material *m, float raduis);
void      sphere_set_transform(t_sphere *s, float **matrix, void (*f)(void *));
#endif // !ENTITY_H
