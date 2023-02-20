/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:01:48 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/06 21:30:55 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "vue.h"

t_world	*init_cam(t_world *world, char **tab, char **coord, char **orio)
{
	t_point	*up;

	up = point_create(0, 1, 0);
	world->camera = camera(VUE_WIDTH, VUE_HEIGHT, ft_atof(tab[3]) * M_PI / 180);
	matrix_free_4(world->camera->transform);
	world->camera->origin = vector_create(ft_atof(coord[0]),
			ft_atof(coord[1]), ft_atof(coord[2]));
	world->camera->orient = point_create(ft_atof(orio[0]),
			ft_atof(orio[1]), ft_atof(orio[2]));
	world->camera->transform = camera_transform(world->camera->origin,
			world->camera->orient, up);
	world->camera->inv_transform = matrix_invert_4(world->camera->transform);
	free(up);
	return (world);
}
	// char		**tab;//info[0]
	// char		**coord;//info[1]
	// char		**orio;//info[2]

t_world	*parse_cam(char *line, t_world *world)
{
	char	**info[3];

	info[0] = ft_split(line, ' ');
	info[0] = test_field(info[0], 4);
	if (comma_check(info[0], 3) == 0)
	{
		free(info[0]);
		return (NULL);
	}
	info[1] = ft_split(info[0][1], ',');
	info[1] = test_field(info[1], 3);
	info[2] = ft_split(info[0][2], ',');
	info[2] = test_field(info[2], 3);
	world = init_cam(world, info[0], info[1], info[2]);
	free_tab(info[2]);
	free_tab(info[1]);
	free_tab(info[0]);
	return (world);
}

int	check_cam(char *line)
{
	if (line[0] == 'C' && !check_fields_comma(line, 3))
	{
		free(line);
		return (0);
	}
	else
	{
		free(line);
		return (1);
	}
	return (1);
}

int	check_c(char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		if (line[0] == 'C' && line[1] == ' ')
			i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (i != 1)
		return (0);
	return (1);
}
