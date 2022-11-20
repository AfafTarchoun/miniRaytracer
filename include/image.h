/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:51:12 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 02:21:57 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "types.h"
# include "../libs/libft/libft.h"

t_image	*image_init(t_vue *vue);
void	image_put_pixel(t_image *image, int x, int y, int color);
#endif
