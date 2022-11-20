/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 22:46:59 by atarchou         ###   ########.fr       */
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

// double atof(char *line)
// {
// 	double num;
// 	int sign;
// 	char *pos;

// 	pos = 0;
// 	sign = 1;
// 	num = 0;
// 	if(*line == '-')
// 	{
// 		sign = -1;
// 		++(line);
// 	}
// 	while(ft_isdigit(*line) || *line == '.')
// 	{
// 		if (*line == '.')
// 			pos = (line + 1);
// 		else
// 			num = num * 10 + (*line - '0');
// 		++(line);
// 	}
// 	// if (!pos)
// 		// return (num * sign);
// 	return (num / pow(10, line - pos) * sign) ;
// }

t_vec3 init_vec(double x, double y, double z)
{
	t_vec3 res;
	
	res.x = x;
	res.y = y;
	res.z = z;
	return(res);
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
	scene->camera->fov = (double)atof(tab[3]);
	scene->camera->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	scene->camera->orientation = init_vec((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	return (scene);
}

t_scene *parse_ambient(char *line, t_scene *scene)
{
	char **tab;
	char **col;
	
	scene->ambient_light = ft_calloc(1, sizeof(t_ambient_light_attr));
	tab = ft_split(line, '|');
	col = ft_split(tab[2], ' ');
	scene->ambient_light->ratio = (double)atof(tab[1]);
	scene->ambient_light->color = init_vec((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	return (scene);
}

t_scene *parse_light(char *line, t_scene *scene)
{
	char **tab;
	char **coord;
	
	scene->light = ft_calloc(1, sizeof(t_light_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	scene->light->brightness = (double)atof(tab[2]);
	scene->light->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
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
	sp->diameter = (double)atof(tab[2]);
	sp->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	sp->color = init_vec((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
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
	pl->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	pl->orientation = init_vec((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	pl->color = init_vec((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
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
	cy->diameter = (double)atof(tab[3]);
	cy->height = (double)atof(tab[4]);
	cy->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	cy->orientation = init_vec((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	cy->color = init_vec((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
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
	scene = ft_calloc(1, sizeof(t_scene));
	scene = parse_file(argv[1], scene);
	vue = vue_init();
	render(vue, scene);
	mlx_loop(vue->mlx);
	return 0;
}
