/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 03:42:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../include/image.h"
// #include "libft.h"
#include "mlx.h"
#include "../include/renderer.h"
#include "../include/types.h"
#include "../include/vue.h"
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include <fcntl.h>
#include <stdio.h>
#include "../include/parser/parser.h"

void print_usage()
{
	ft_putendl_fd("usage: ./minirt filename.rt", 2);
}

// t_scene *simple_scene()
// {
// 	t_scene       *scene;
// 	t_sphere_attr *sphere;
// 	scene = ft_calloc(1, sizeof(t_scene));
	
// 	t_shape *shape = ft_calloc(1, sizeof(t_shape));
// 	shape->type = SPHERE;
// 	shape->attr = sphere;
// 	ft_lstadd_back(&scene->objects, ft_lstnew(shape));
// 	return (scene);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void parse_cam(char *line, t_scene *scene)
{
	char **tab;
	char **coord;
	char **orio;
	
	scene->camera = ft_calloc(1, sizeof(t_camera_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	orio = ft_split(tab[2], ' ');
	scene->camera->fov = atof(tab[3]);
	scene->camera->coordinates.x = atof(coord[0]);
	scene->camera->coordinates.y = atof(coord[1]);
	scene->camera->coordinates.z = atof(coord[2]);
	scene->camera->orientation.x = atof(orio[0]);
	scene->camera->orientation.y = atof(orio[1]);
	scene->camera->orientation.z = atof(orio[2]);
	return ;
}

void parse_ambient(char *line, t_scene *scene)
{
	char **tab;
	char **col;
	
	scene->ambient_light = ft_calloc(1, sizeof(t_ambient_light_attr));
	tab = ft_split(line, '|');
	col = ft_split(tab[2], ' ');
	scene->ambient_light->ratio = atof(tab[1]);
	scene->ambient_light->color.x = atof(col[0]);
	scene->ambient_light->color.y = atof(col[1]);
	scene->ambient_light->color.z = atof(col[2]);
	return ;
}

void parse_light(char *line, t_scene *scene)
{
	char **tab;
	char **coord;
	
	scene->light = ft_calloc(1, sizeof(t_light_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	scene->light->brightness = atof(tab[3]);
	scene->light->coordinates.x = atof(coord[0]);
	scene->light->coordinates.y = atof(coord[1]);
	scene->light->coordinates.z = atof(coord[2]);
	return ;
}
void parse_sphere(char *line)
{
	t_sphere_attr *sp;
	char **tab;
	char **coord;
	char **col;

	sp = malloc(sizeof(t_sphere_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	col = ft_split(tab[3], ' ');
	sp->diameter = atof(tab[2]);
	sp->coordinates.x = atof(coord[0]);
	sp->coordinates.y = atof(coord[1]);
	sp->coordinates.z = atof(coord[2]);
	sp->color.x = atof(col[0]);
	sp->color.y = atof(col[1]);
	sp->color.z = atof(col[2]);
	return ;
}

void parse_plane(char *line)
{
	t_plane_attr *pl;
	char **tab;
	char **coord;
	char **orio;
	char **col;
	
	pl = malloc(sizeof(t_plane_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	orio = ft_split(tab[2], ' ');
	col = ft_split(tab[3], ' ');
	pl->coordinates.x = atof(coord[0]);
	pl->coordinates.y = atof(coord[1]);
	pl->coordinates.z = atof(coord[2]);
	pl->orientation.x = atof(orio[0]);
	pl->orientation.y = atof(orio[1]);
	pl->orientation.z = atof(orio[2]);
	pl->color.x = atof(col[0]);
	pl->color.y = atof(col[1]);
	pl->color.z = atof(col[2]);
	return ;
}

void parse_cylinder(char *line)
{
	t_cylinder_attr *cy;
	char **tab;
	char **coord;
	char **orio;
	char **col;
	
	cy = malloc(sizeof(t_cylinder_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	orio = ft_split(tab[2], ' ');
	col = ft_split(tab[5], ' ');
	cy->diameter = atof(tab[3]);
	cy->height = atof(tab[4]);
	cy->coordinates.x = atof(coord[0]);
	cy->coordinates.y = atof(coord[1]);
	cy->coordinates.z = atof(coord[2]);
	cy->orientation.x = atof(orio[0]);
	cy->orientation.y = atof(orio[1]);
	cy->orientation.z = atof(orio[2]);
	cy->color.x = atof(col[0]);
	cy->color.y = atof(col[1]);
	cy->color.z = atof(col[2]);
	return ;
}

void parse_obj(char *line)
{
	t_scene *scene;
	
	scene = ft_calloc(1, sizeof(t_scene));
	if (line[0] == 'C' && line[1] == '|')
		parse_cam(line, scene);
	else if (line[0] == 'A')
		parse_ambient(line, scene);
	else if (line[0] == 'L')
		parse_light(line,scene);
	else if (line[0] == 'S' && line[1] == 'P')
		parse_sphere(line);
	// else if (line[0] == 'P' && line[1] == 'L')
	// 	parse_plane(line);
	// else if (line[0] == 'C' && line[1] == 'Y')
	// 	parse_cylinder(line);
	else
		return ;
}

void parse_file(char *file)
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
        if (line[0] != '\0')
			parse_obj(line);
        // free (line);
    }
    close(fd);
    return ;
}

t_scene *simple_scene()
{
	t_scene *scene;

	scene = ft_calloc(1, sizeof(t_scene));
	return (scene);
}

int main(int argc, char *argv[])
{
	t_scene *scene;
	t_vue   *vue;

	if (argc != 2)
	{
		print_usage();
		return (1);
	}
	// (void) argv;
	parse_file(argv[1]);
	scene = simple_scene();
	vue = vue_init();
	render(vue, scene);
	mlx_loop(vue->mlx);
	return 0;
}
