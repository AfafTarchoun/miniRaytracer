/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 18:05:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../include/image.h"
// #include "libft.h"
#include "mlx.h"
#include <math.h>
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

double ft_atod(char *line)
{
	double num;
	int sign;
	char *pos;

	pos = 0;
	sign = 1;
	num = 0;
	if(*line == '-')
	{
		sign = -1;
		++(line);
	}
	while(ft_isdigit(*line) || *line == '.')
	{
		if (*line == '.')
			pos = (line + 1);
		else
			num = num * 10 + (*line - '0');
		++(line);
	}
	// if (!pos)
		// return (num * sign);
	return (num / pow(10, line - pos) * sign) ;
}

t_scene *parse_cam(char *line, t_scene *scene)
{
	char **tab;
	char **coord;
	char **orio;
	
	scene->camera = ft_calloc(1, sizeof(t_camera_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	orio = ft_split(tab[2], ' ');
	scene->camera->fov = ft_atod(tab[3]);
	scene->camera->coordinates.x = ft_atod(coord[0]);
	scene->camera->coordinates.y = ft_atod(coord[1]);
	scene->camera->coordinates.z = ft_atod(coord[2]);
	scene->camera->orientation.x = ft_atod(orio[0]);
	scene->camera->orientation.y = ft_atod(orio[1]);
	scene->camera->orientation.z = ft_atod(orio[2]);
	return (scene);
}

t_scene *parse_ambient(char *line, t_scene *scene)
{
	char **tab;
	char **col;
	
	scene->ambient_light = ft_calloc(1, sizeof(t_ambient_light_attr));
	tab = ft_split(line, '|');
	col = ft_split(tab[2], ' ');
	scene->ambient_light->ratio = ft_atod(tab[1]);
	scene->ambient_light->color.x = ft_atod(col[0]);
	scene->ambient_light->color.y = ft_atod(col[1]);
	scene->ambient_light->color.z = ft_atod(col[2]);
	return (scene);
}

t_scene *parse_light(char *line, t_scene *scene)
{
	char **tab;
	char **coord;
	
	scene->light = ft_calloc(1, sizeof(t_light_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	scene->light->brightness = ft_atod(tab[2]);
	scene->light->coordinates.x = ft_atod(coord[0]);
	scene->light->coordinates.y = ft_atod(coord[1]);
	scene->light->coordinates.z = ft_atod(coord[2]);
	return (scene);
}

t_shape *parse_sphere(char *line)
{
	t_sphere_attr *sp;
	t_shape *shape;
	char **tab;
	char **coord;
	char **col;

	shape = ft_calloc(1, sizeof(t_shape));
	sp = malloc(sizeof(t_sphere_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	col = ft_split(tab[3], ' ');
	sp->diameter = ft_atod(tab[2]);
	sp->coordinates.x = ft_atod(coord[0]);
	sp->coordinates.y = ft_atod(coord[1]);
	sp->coordinates.z = ft_atod(coord[2]);
	sp->color.x = ft_atod(col[0]);
	sp->color.y = ft_atod(col[1]);
	sp->color.z = ft_atod(col[2]);
	shape->type = SPHERE;
	shape->attr = sp;
	return (shape);
}

t_shape *parse_plane(char *line)
{
	t_plane_attr *pl;
	t_shape *shape;
	char **tab;
	char **coord;
	char **orio;
	char **col;

	shape = ft_calloc(1, sizeof(t_shape));
	pl = malloc(sizeof(t_plane_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	orio = ft_split(tab[2], ' ');
	col = ft_split(tab[3], ' ');
	pl->coordinates.x = ft_atod(coord[0]);
	pl->coordinates.y = ft_atod(coord[1]);
	pl->coordinates.z = ft_atod(coord[2]);
	pl->orientation.x = ft_atod(orio[0]);
	pl->orientation.y = ft_atod(orio[1]);
	pl->orientation.z = ft_atod(orio[2]);
	pl->color.x = ft_atod(col[0]);
	pl->color.y = ft_atod(col[1]);
	pl->color.z = ft_atod(col[2]);
	shape->type = PLANE;
	shape->attr = pl;
	return (shape);
}

t_shape *parse_cylinder(char *line)
{
	t_cylinder_attr *cy;
	t_shape *shape;
	char **tab;
	char **coord;
	char **orio;
	char **col;

	shape = ft_calloc(1, sizeof(t_shape));
	cy = malloc(sizeof(t_cylinder_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	orio = ft_split(tab[2], ' ');
	col = ft_split(tab[5], ' ');
	cy->diameter = ft_atod(tab[3]);
	cy->height = ft_atod(tab[4]);
	cy->coordinates.x = ft_atod(coord[0]);
	cy->coordinates.y = ft_atod(coord[1]);
	cy->coordinates.z = ft_atod(coord[2]);
	cy->orientation.x = ft_atod(orio[0]);
	cy->orientation.y = ft_atod(orio[1]);
	cy->orientation.z = ft_atod(orio[2]);
	cy->color.x = ft_atod(col[0]);
	cy->color.y = ft_atod(col[1]);
	cy->color.z = ft_atod(col[2]);
	shape->type = CYLINDER;
	shape->attr = cy;
	return (shape);
}

// t_scene *not_objs(char *line, t_scene *scene)
// {
// 	if (line[0] == 'C' && line[1] == '|')
// 		scene = parse_cam(line, scene);
// 	if (line[0] == 'A')
// 		scene = parse_ambient(line, scene);
// 	if (line[0] == 'L')
// 		scene = parse_light(line,scene);
// 	return (scene);
// }

// t_scene *parse_objs(char *line, t_scene *scene)
// {
// 	t_shape *shape;

// 	shape = NULL;
// 	if (line[0] == 'C' && line[1] == '|')
// 		scene = parse_cam(line, scene);
// 	else if (line[0] == 'A')
// 		scene = parse_ambient(line, scene);
// 	else if (line[0] == 'L')
// 		scene = parse_light(line,scene);
// 	else if (line[0] == 'S' && line[1] == 'P')
// 		shape = parse_sphere(line);
// 	else if (line[0] == 'P' && line[1] == 'L')
// 		shape = parse_plane(line);
// 	else if (line[0] == 'C' && line[1] == 'Y')
// 		shape = parse_cylinder(line);
// 	if (shape != NULL)
// 		ft_lstadd_back(&scene->objects, ft_lstnew(shape));
// 	return (scene);
// }

t_scene *parse_line(char *line, t_scene *scene)
{
	t_shape *shape;

	shape = NULL;
	if (line[0] == 'C' && line[1] == '|')
		scene = parse_cam(line, scene);
	else if (line[0] == 'A')
		scene = parse_ambient(line, scene);
	else if (line[0] == 'L')
		scene = parse_light(line,scene);
	else if (line[0] == 'S' && line[1] == 'P')
		shape = parse_sphere(line);
	else if (line[0] == 'P' && line[1] == 'L')
		shape = parse_plane(line);
	else if (line[0] == 'C' && line[1] == 'Y')
		shape = parse_cylinder(line);
	if (shape != NULL)
		ft_lstadd_back(&scene->objects, ft_lstnew(shape));
	return (scene);
}

t_scene *parse_file(char *file, t_scene *scene)
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
			scene = parse_line(line, scene);
        free(line);
    }
    close(fd);
    return(scene);
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
	write(1, "hi", 2);
	scene = ft_calloc(1, sizeof(t_scene));
	scene = parse_file(argv[1], scene);
	vue = vue_init();
	render(vue, scene);
	mlx_loop(vue->mlx);
	return 0;
}
