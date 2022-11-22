/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/22 12:25:42 by atarchou         ###   ########.fr       */
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
	int i;
	
	i = 0;
	scene->camera = ft_calloc(1, sizeof(t_camera_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	orio = ft_split(tab[2], ' ');
	while(orio[i])
		i++;
	if(i != 3)
		return NULL;
	scene->camera->fov = (double)atof(tab[3]);
	scene->camera->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	scene->camera->orientation = init_vec((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	return (scene);
}

t_scene *parse_ambient(char *line, t_scene *scene)
{
	char **tab;
	char **col;
	int i;
	
	i = 0;
	scene->ambient_light = ft_calloc(1, sizeof(t_ambient_light_attr));
	tab = ft_split(line, '|');
	col = ft_split(tab[2], ' ');
	while(col[i])
		i++;
	if(i != 3)
		return NULL;
	scene->ambient_light->ratio = (double)atof(tab[1]);
	scene->ambient_light->color = init_vec((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	return (scene);
}

t_scene *parse_light(char *line, t_scene *scene)
{
	char **tab;
	char **coord;
	int i;
	
	i = 0;
	scene->light = ft_calloc(1, sizeof(t_light_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	scene->light->brightness = (double)atof(tab[2]);
	scene->light->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	return (scene);
}

t_shape *parse_sphere(char *line)
{
	t_sphere_attr *sp;
	t_shape *shape;
	int i;
	char **tab;
	char **coord;
	char **col;
	
	i = 0;
	shape = ft_calloc(1, sizeof(t_shape));
	sp = malloc(sizeof(t_sphere_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	col = ft_split(tab[3], ' ');
	while(col[i])
		i++;
	if(i != 3)
		return 0;
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
	int i;

	i = 0;
	shape = ft_calloc(1, sizeof(t_shape));
	pl = malloc(sizeof(t_plane_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	orio = ft_split(tab[2], ' ');
	while(orio[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	col = ft_split(tab[3], ' ');
	while(orio[i])
		i++;
	if(i != 3)
		return NULL;
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
	int i;
	
	i = 0;
	shape = ft_calloc(1, sizeof(t_shape));
	cy = malloc(sizeof(t_cylinder_attr));
	tab = ft_split(line, '|');
	coord = ft_split(tab[1], ' ');
	while(coord[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	orio = ft_split(tab[2], ' ');
	while(orio[i])
		i++;
	if(i != 3)
		return NULL;
	i = 0;
	col = ft_split(tab[5], ' ');
	while(col[i])
		i++;
	if(i != 3)
		return NULL;
	cy->diameter = (double)atof(tab[3]);
	cy->height = (double)atof(tab[4]);
	cy->coordinates = init_vec((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	cy->orientation = init_vec((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	cy->color = init_vec((double)atof(col[0]), (double)atof(col[1]), (double)atof(col[2]));
	shape->type = CYLINDER;
	shape->attr = cy;
	return (shape);
}

t_scene *parse_line(char *line, t_scene *scene)
{
	t_shape *shape;

	shape = NULL;
	if (line[0] == 'C' && line[1] == '|')
	{		
		scene = parse_cam(line, scene);
		if(!scene)
			return (NULL);
	}
	else if (line[0] == 'A')
	{		
		scene = parse_ambient(line, scene);
		if(!scene)
			return (NULL);
	}
	else if (line[0] == 'L')
	{		
		scene = parse_light(line,scene);
		if(!scene)
			return (NULL);
	}
	else if (line[0] == 'S' && line[1] == 'P')
	{	
		shape = parse_sphere(line);
		if (!shape)
			return NULL;
	}
	else if (line[0] == 'P' && line[1] == 'L')
	{		
		shape = parse_plane(line);
		if (!shape)
			return NULL;
	}
	else if (line[0] == 'C' && line[1] == 'Y')
	{		
		shape = parse_cylinder(line);
		if (!shape)
			return NULL;
	}
	if (shape != NULL)
		ft_lstadd_back(&scene->objects, ft_lstnew(shape));
	return (scene);
}

int	ft_isdouble(char *src)
{
	int	i;
	int	decimal_point;

	i = 0;
	if (*src == '-')
		i++;
	decimal_point = 0;
	while (*(src + i) != '\0')
	{
		if (ft_isdigit(*(src + i)))
			;
		else if (decimal_point == 0 && *(src + i) == '.')
			decimal_point = 1;
		else
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char *no_newline(char *line)
{
	int i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	char *new = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (line[++i] && line[i] != '\n')
		new[i] = line[i];
	new[i] = 0;
	return new;
}

int check_fields_pipe(char *line, int nb)
{
	char **fields;
	char **info;
	int i;
	int j;
	
	i = 0;
	j = 0;
	char *new = no_newline(line);
	fields = ft_split(new, '|');
	while(fields[i])
		i++;
	if (i != nb + 1)
		return(0);
	i = 1;
	while(i <= nb)
	{
		info = ft_split(fields[i], ' ');
		j = 0;
		while(info[j])
		{
			if(!ft_isdouble(info[j]))
				return(0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	handle_cam(char *file)
{
	int fd;
	char *line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) > 0)
	{
		if (line[0] != 'C')
		{			
			free(line);
			return (0);
		}
		else if (line[0] == 'C' && !check_fields_pipe(line, 3))
		{
			free(line);
			return (0);
		}
		else
		{
			free(line);
			return (1);
		}
	}
	close(fd);
	return (1);
}

int error_management(char *file)
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
		if (line[0] == 'L' && !check_fields_pipe(line, 2))
		{
			free(line);
			return (0);
		}
		else if (line[0] == 'A' && !check_fields_pipe(line, 2))
		{
			free(line);
			return (0);
		}
		if (line[0] == 'S' && line[1] == 'P' && !check_fields_pipe(line, 3))
		{
			free(line);
			return (0);
		}
		else if (line[0] == 'P' && line[1] == 'L' && !check_fields_pipe(line, 3))
		{
			free(line);
			return (0);
		}
		else if (line[0] == 'C' && line[1] == 'Y' && !check_fields_pipe(line, 5))
		{
			free(line);
			return (0);
		}
    }
    close(fd);
    return(1);
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
	t_scene *scene;
	t_vue   *vue;

	if (argc != 2)
	{
		print_usage();
		return (1);
	}
	if (handle_cam(argv[1])!= 1)
		return (0);
	if (error_management(argv[1])!= 1)
		return (0);
	scene = ft_calloc(1, sizeof(t_scene));
	scene = parse_file(argv[1], scene);
	if(!scene)
		return 0;
	vue = vue_init();
	render(vue, scene);
	mlx_loop(vue->mlx);
	return (0);
}
