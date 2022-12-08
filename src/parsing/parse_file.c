/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:39:17 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/08 04:15:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing/parser.h"

t_world *parse_line(char *line, t_world *scene)
{
	t_entity *shape;

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
		ft_lstadd_back(&scene->objs, ft_lstnew(shape));
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
	int i;
	char *new;
	
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
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
	char *new;
	int i;
	int j;
	
	i = 0;
	new = no_newline(line);
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
	free_tab(fields);
	free_tab(info);
	free(new);
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
		free(line);
    }
    close(fd);
    return(1);
}