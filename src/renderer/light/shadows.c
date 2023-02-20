/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:46:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "renderer.h"

int	is_shadowed(t_world *world, t_vector *point)
{
	t_vector	*light_to_p;
	t_ray		*r;
	t_list		*hits;
	t_list		*tmp;
	t_hit		*hit;
	double		dist;

	light_to_p = tuple_sub(world->light->pos, point);
	dist = tuple_length(light_to_p);
	light_to_p = tuple_normalize_f(light_to_p, free);
	r = ray(point, light_to_p);
	hits = get_all_hits(world->objs, r);
	free(light_to_p);
	free(r);
	if (!hits)
	{
		ft_lstclear(&hits, hit_delete);
		return (0);
	}
	tmp = hits;
	while (tmp)
	{
		hit = tmp->content;
		if (hit && which_positive_and_low(hit->t1, hit->t2) < dist)
		{
			ft_lstclear(&hits, hit_delete);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&hits, hit_delete);
	return (0);
}

int	is_shadowed_cy(t_world *world, t_vector *point)
{
	t_vector	*light_to_p;
	t_ray		*r;
	t_list		*hits;
	t_list		*tmp;
	t_hit		*hit;
	double		dist;

	point = tuple_scale_f(point, EPSILON, 0);
	light_to_p = tuple_sub(world->light->pos, point);
	dist = tuple_length(light_to_p);
	light_to_p = tuple_normalize_f(light_to_p, free);
	r = ray(point, light_to_p);
	hits = get_all_hits(world->objs, r);
	free(light_to_p);
	free(r);
	if (!hits)
	{
		ft_lstclear(&hits, hit_delete);
		return (0);
	}
	tmp = hits;
	while (tmp)
	{
		hit = tmp->content;
		if (hit && which_positive_and_low(hit->t1, hit->t2) < dist)
		{
			ft_lstclear(&hits, hit_delete);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&hits, hit_delete);
	return (0);
}