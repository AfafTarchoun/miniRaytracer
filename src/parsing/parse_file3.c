/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:20:12 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/05 18:28:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "utils.h"

int	check_element(char *str, int i)
{
	if (str[i] == 'L' || str[i] == 'C' || str[i] == 'A'
		|| (str[i] == 'p' && str[i +1] == 'l')
		|| (str[i] == 's' && str[i +1] == 'p')
		|| (str[i] == 'c' && str[i +1] == 'y')
		|| str[i] == '\n')
		return (1);
	else
		return (0);
	return (1);
}

int	check_element1(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return_error();
	line = get_next_line(fd);
	while (line > 0)
	{
		if (check_element(line, 0) == 0)
		{
			free(line);
			error_print();
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}

int	handle_cam_second_half(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line > 0)
	{
		if (check_cam(line) != 1)
			return (0);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	handle_cam_first_half(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = NULL;
	if (check_c(line, fd) != 1)
	{
		free(line);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (check_a(line, fd) != 1)
	{
		free(line);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (check_l(line, fd) != 1)
	{
		free(line);
		return (0);
	}
	line = NULL;
	return (fd);
}

int	handle_cam(char *file)
{
	int	result;

	result = handle_cam_first_half(file);
	if (result > 0)
		result = handle_cam_second_half(result);
	return (result);
}
