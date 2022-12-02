/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:01:48 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/02 21:36:23 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing/parser.h"
#include "vue.h"
t_world *parse_cam(char *line, t_world *world)
{
	char **tab;
	char **coord;
	char **orio;
	int i;
	
	i = 0;
	world->camera = ft_calloc(1, sizeof(t_camera));
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
	world->camera->fov = (double)atof(tab[3]);
	world->camera = camera(VUE_WIDTH, VUE_HEIGHT, world->camera->fov);
	matrix_free_4(world->camera->transform);
	world->camera->origin = vector_create((double)atof(coord[0]), (double)atof(coord[1]), (double)atof(coord[2]));
	world->camera->orient = vector_create((double)atof(orio[0]), (double)atof(orio[1]), (double)atof(orio[2]));
	world->camera->transform = matrix_translate_creat_4(world->camera->origin, free);
	free_tab(orio);
	free_tab(coord);
	free_tab(tab);	
	// printf("diam %lf\n", world->camera->fov);
	// printf("coord %lf %lf %lf\n",world->camera->origin->x , world->camera->origin->y, world->camera->origin->z);
	// printf("col %lf %lf %lf\n",world->camera->orient->x , world->camera->orient->y, world->camera->orient->z);
	return (world);
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