/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:34 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/05 21:06:58 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "get_next_line.h"
#include "image.h"
#include "libft.h"
#include "mlx.h"
#include "hooks.h"
#include "renderer.h"
#include "vue.h"
#include "utils.h"
#include "world.h"
#include "shadow.h"

void	print_usage(void)
{
	ft_putendl_fd("usage: ./minirt filename.rt", 2);
}

int	check_extension(char *str)
{
	char	*ext;

	if (!ft_strcmp(str, ".rt"))
		return (0);
	ext = ft_strrchr(str, '.');
	if (!ext)
		return (0);
	if (!ft_strcmp(ext, ".rt"))
		return (1);
	return (0);
}

t_world	*parser(t_world *world, char *str)
{
	if (handle_cam(str) != 1)
	{
		printf("Error: Camera none existing or wrong\n");
		return (0);
	}
	if (error_management(str) != 1)
		return (0);
	world = ft_calloc(1, sizeof(t_world));
	world = parse_file(str, world);
	return (world);
}

void	error_print(void)
{
	printf("Error: File information none existing or wrong\n");
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_world	*world;
	t_vue	*vue;
	t_image	*image;

	if (argc != 2 || !check_extension(argv[1]))
		error_print();
	vue = vue_init();
	world = NULL;
	world = parser(world, argv[1]);
	if (!world)
		error_print();
	image = render(world, vue);
	world_delete(world);
	mlx_put_image_to_window(vue->mlx, vue->window, image->img, 0, 0);
	free(image);
	mlx_hook(vue->window, 17, 0, x_exit, 0);
	mlx_hook(vue->window, 2, 1L << 0, key_hook, 0);
	mlx_loop(vue->mlx);
	return (0);
}
