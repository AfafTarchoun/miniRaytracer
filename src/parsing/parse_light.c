/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:07:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/05 18:23:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing/parser.h"

int	check_l(char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		if (line[0] == 'L' && line[1] == ' ')
			i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (i != 1)
		return (0);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_light	*fill_light(char **tab, char **coord)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	light->intensity = ft_atof(tab[2]);
	light->pos = vector_create(ft_atof(coord[0]),
			ft_atof(coord[1]), ft_atof(coord[2]));
	return (light);
}

t_world	*parse_light(char *line, t_world *world)
{
	char	**tab;
	char	**coord;

	tab = ft_split(line, ' ');
	tab = test_field(tab, 3);
	if (comma_check(tab, 2) == 0)
	{
		free(tab);
		return (NULL);
	}
	coord = ft_split(tab[1], ',');
	coord = test_field(coord, 3);
	world->light = fill_light(tab, coord);
	free_tab(tab);
	free_tab(coord);
	return (world);
}
