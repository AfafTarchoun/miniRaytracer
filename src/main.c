/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/08 04:14:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/parsing/parser.h"
// #include "camera.h"
// #include "color.h"
// #include "entity.h"
// #include "get_next_line.h"
// #include "hit.h"
// #include "image.h"
// #include "libft.h"
// #include "material.h"
// #include "matrix.h"
#include "mlx.h"
// #include "normals.h"
// #include "point.h"
// #include "ray.h"
// #include "reflection.h"
#include "renderer.h"
// #include "tuple.h"
// #include "types.h"
// #include "vector.h"
#include "vue.h"
// #include <fcntl.h>
// #include <math.h>
// #include <stdio.h>

void print_usage()
{
	ft_putendl_fd("usage: ./minirt filename.rt", 2);
}

t_world *parse_file(char *file, t_world *scene)
{
    int fd;
    char *line;
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("error\n");
        return(0);
    }
    while((line = get_next_line(fd)) > 0)
    {
        if ((line[0] != '\0'))
		{	
			scene = parse_line(line, scene);
			if(!scene)
				return NULL;
		}
        free(line);
    }
    close(fd);
    return(scene);
}

int main(int argc, char *argv[])
{
	t_world *world;
	t_vue   *vue;
	t_image *image;

	if (argc != 2)
	{
		print_usage();
		return (1);
	}
	if (handle_cam(argv[1])!= 1)
		return (0);
	if (error_management(argv[1])!= 1)
		return (0);
	vue = vue_init();
	world = ft_calloc(1, sizeof(t_world));
	world = parse_file(argv[1], world);
	if(!world)
		return 0;
	image = render(world, vue);
	mlx_put_image_to_window(vue->mlx, vue->window, image->img, 0, 0);
	mlx_loop(vue->mlx);
	// free(world);
	// system("leaks minirt");
	return (0);
}