/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:56:13 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 15:51:22 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALS_H
#define NORMALS_H

#include "types.h"

t_vector *normal_at_sphere(t_sphere *sphere, t_point *w_point, void (*f)(void *));

#endif // !DEBUG
