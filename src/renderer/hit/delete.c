/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:03:32 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/04 05:48:12 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

void	hit_delete(void *_hit)
{
	t_hit	*hit;

	hit = _hit;
	free(hit->eyev);
	free(hit->hitpoint);
	free(hit->norm);
	free(hit->entity);
	free(_hit);
}

void	hit_delete_2d_list(t_list ***hits, t_camera *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->hsize)
	{
		j = 0;
		while (j < c->wsize)
		{
			if (hits[i][j])
				ft_lstclear(&hits[i][j], hit_delete);
			j++;
		}
		free(hits[i]);
		i++;
	}
	free(hits);
}
