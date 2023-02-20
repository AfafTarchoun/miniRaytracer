/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:06:14 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "utils.h"

char	*no_newline(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (line[++i] && line[i] != '\n')
		new[i] = line[i];
	new[i] = 0;
	return (new);
}

int	loop_fields(char **fields, int nb)
{
	char	**info;
	int		i;
	int		j;

	i = 1;
	info = ft_split(fields[i], ',');
	while (i <= nb)
	{
		j = 0;
		while (info[j])
		{
			if (!ft_isdouble(info[j]))
				return (0);
			j++;
		}
		i++;
	}
	free_tab(info);
	return (1);
}

int	check_fields_comma(char *line, int nb)
{
	char	**fields;
	char	*new;
	int		i;

	i = 0;
	new = no_newline(line);
	fields = ft_split(new, ' ');
	while (fields[i])
		i++;
	if (i != nb + 1)
		return (0);
	if (!loop_fields(fields, nb))
		return (0);
	free_tab(fields);
	free(new);
	return (1);
}

int	check_fields(char *line)
{
	if (line[0] == 'A' && line[1] == ' '
		&& !check_fields_comma(line, 2))
	{
		free(line);
		return (0);
	}
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' '
		&& !check_fields_comma(line, 3))
	{
		free(line);
		return (0);
	}
	else if (line[0] == 'p' && line[1] == 'l'
		&& line[2] == ' ' && !check_fields_comma(line, 3))
	{
		free(line);
		return (0);
	}
	else if (line[0] == 'c' && line[1] == 'y'
		&& line[2] == ' ' && !check_fields_comma(line, 5))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	error_management(char *file)
{
	int		fd;
	char	*line;

	line = 0;
	check_element1(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return_error();
	line = get_next_line(fd);
	while (line > 0)
	{
		if (line[0] == 'L' && line[1] == ' '
			&& !check_fields_comma(line, 2))
		{
			free(line);
			return (0);
		}
		if (!check_fields(line))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}
