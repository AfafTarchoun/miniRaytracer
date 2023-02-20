/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:17:44 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/05 18:22:46 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"

int	check_a(char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		if (line[0] == 'A' && line[1] == ' ')
			i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (i != 1)
		return (0);
	return (1);
}

int	comma_check(char **tab, int nb)
{
	int	i;

	i = 0;
	while (tab[nb][i])
	{
		if (tab[nb][i] == ',' )
			return (0);
		i++;
	}
	return (1);
}

t_a_light	*fill_alight(char **tab, char **col)
{
	t_a_light	*alight;

	alight = ft_calloc(1, sizeof(t_a_light));
	alight->ratio = ft_atof(tab[1]);
	alight->material = material();
	free(alight->material->color);
	alight->material->color = vector_create(ft_atof(col[0]),
			ft_atof(col[1]), ft_atof(col[2]));
	alight->material->color = tuple_div_f(alight->material->color,
			255, free);
	return (alight);
}

t_world	*parse_ambient(char *line, t_world *world)
{
	char	**tab;
	char	**col;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	tab = test_field(tab, 3);
	if (comma_check(tab, 1) == 0)
	{
		free(tab);
		return (NULL);
	}
	col = ft_split(tab[2], ',');
	while (col[i])
		i++;
	if (i != 3)
		return (NULL);
	world->alight = fill_alight(tab, col);
	free_tab(col);
	free_tab(tab);
	return (world);
}
