/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:43 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H
# include "types.h"

t_entity	*entity(t_entity_type type, void *obj);
t_sphere	*sphere(t_point *origin, t_material *m, double raduis);
void		sphere_set_transform(t_sphere *s,
				double **matrix, void (*f)(void *));
void		sphere_delete(void *_s);
void		plane_delete(void *_p);
void		cylinder_delete(void *_cy);
void		entity_delete(void *_e);
#endif // !ENTITY_H
