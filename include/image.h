/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:51:12 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:01:46 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "libft.h"
# include "types.h"

t_image	*image_init(t_vue *vue, t_camera *cam);
void	image_put_pixel(t_image *image, int x, int y, t_color *color);
#endif
