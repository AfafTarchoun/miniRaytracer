/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:51:12 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/25 10:52:08 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
#define IMAGE_H
#include "libft.h"
#include "types.h"

t_image *image_init(t_vue *vue, t_camera *cam);
void     image_put_pixel(t_image *image, int x, int y, int color);
#endif
