/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:51:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/08/26 17:51:45 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "image.h"
#include "defs.h"
#include "mlx.h"

static void	*image_print_err_return_null(void)
{
	ft_putstr_fd(IMAGE_COULD_NOT_BE_CREATED, 2);
	return (NULL);
}

t_image	*image_init(t_vue *vue)
{
	t_image	*image;

	if (NOT vue OR NOT vue->mlx)
		return (image_print_err_return_null());
	image = ft_calloc(1, sizeof(t_image));
	if (NOT image)
		return (image_print_err_return_null());
	image->img = mlx_new_image(vue->mlx, VUE_WIDTH, VUE_HEIGHT);
	if (NOT image->img)
	{
		free(image);
		return (image_print_err_return_null());
	}
	image->addr = mlx_get_data_addr(image->img,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
	return (image);
}

void	image_put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (NOT image)
		return ;
	dst = image->addr
		+ (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
