/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:56:13 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/31 17:05:43 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALS_H
# define NORMALS_H

# include "types.h"

t_vector	*normal_at_sphere(t_sphere *sphere,
				t_point *w_point, void (*f)(void *));
t_vector	*normal_at_plane(t_plane *plane,
				t_point *w_point, void (*f)(void *));
t_vector	*normal_at_cy(t_cylinder *cy, t_point *w_point, void (*f)(void *));
#endif // !DEBUG
