/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:11:05 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/02 19:43:38 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"

t_camera *camera(int w_size, int h_size, float fov);
float   **camera_transform(t_point *from, t_vector *to, t_vector *up);
#endif
