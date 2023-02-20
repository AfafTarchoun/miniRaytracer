/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:39:17 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/05 19:49:46 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"

void	*return_error(void)
{
	printf("error\n");
	exit (1);
}

t_world	*parse_scene(char *line, t_world *scene)
{
	if (line[0] == 'C')
	{
		scene = parse_cam(line, scene);
		if (!scene)
			error_print();
	}
	else if (line[0] == 'A')
	{
		scene = parse_ambient(line, scene);
		if (!scene)
			error_print();
	}
	else if (line[0] == 'L')
	{		
		scene = parse_light(line, scene);
		if (!scene)
			error_print();
	}
	return (scene);
}

t_entity	*parse_entity(char *line, t_entity *shape)
{
	if (line[0] == 's' && line[1] == 'p')
	{
		shape = parse_sphere(line);
		if (!shape)
			error_print();
	}
	else if (line[0] == 'p' && line[1] == 'l')
	{
		shape = parse_plane(line);
		if (!shape)
			error_print();
	}
	else if (line[0] == 'c' && line[1] == 'y')
	{
		shape = parse_cylinder(line);
		if (!shape)
			error_print();
	}
	return (shape);
}

t_world	*parse_line(char *line, t_world *scene)
{
	t_entity	*shape;

	shape = NULL;
	scene = parse_scene(line, scene);
	shape = parse_entity(line, shape);
	if (shape != NULL)
		ft_lstadd_back(&scene->objs, ft_lstnew(shape));
	return (scene);
}

t_world	*parse_file(char *file, t_world *scene)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("eerror\n");
		return (0);
	}
	line = get_next_line(fd);
	while (line > 0)
	{
		if ((line[0] != '\0'))
		{
			scene = parse_line(line, scene);
			if (!scene)
				return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (scene);
}
