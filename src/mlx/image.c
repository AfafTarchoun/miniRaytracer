/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:51:44 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/04 20:07:18 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "defs.h"
#include "mlx.h"

static void	*image_print_err_return_null(void)
{
	ft_putstr_fd(IMAGE_COULD_NOT_BE_CREATED, 2);
	return (NULL);
}

t_image	*image_init(t_vue *vue, t_camera *cam)
{
	t_image	*image;

	if (NOT vue OR NOT vue->mlx)
		return (image_print_err_return_null());
	image = ft_calloc(1, sizeof(t_image));
	if (NOT image)
		return (image_print_err_return_null());
	image->img = mlx_new_image(vue->mlx, cam->wsize, cam->hsize);
	if (NOT image->img)
	{
		free(image);
		return (image_print_err_return_null());
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return (image);
}

static void	ceil_color(t_color *c)
{
	if (c->x > 1.0f)
		c->x = 1;
	if (c->y > 1.0f)
		c->y = 1.0f;
	if (c->z > 1.0f)
		c->z = 1.0f;
}

void	image_put_pixel(t_image *image, int x, int y, t_color *color)
{
	char	*dst;

	if (NOT image)
		return ;
	ceil_color(color);
	color = tuple_scale(color, 255);
	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *) dst = create_trgb(0, color->x, color->y, color->z);
	free(color);
}
