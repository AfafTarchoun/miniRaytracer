/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 06:08:56 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "parsing/parser.h"

void	cylinder_delete(void *_cy)
{
	t_cylinder	*cy;

	cy = _cy;
	free(cy->orient);
	free(cy->origin);
	free(cy->coord);
	free(cy->material->color);
	free(cy->material);
	matrix_free_4(cy->transform);
	matrix_free_4(cy->inv_transform);
	free(cy);
}

t_hit	*hit_cy_create(double t1, double t2, t_cylinder *cy)
{
	t_hit	*hit;

	hit = ft_calloc(1, sizeof(t_hit));
	hit->entity = ft_calloc(1, sizeof(t_entity));
	hit->entity->type = CYLINDER;
	hit->entity->obj = cy;
	hit->t1 = t1;
	hit->t2 = t2;
	return (hit);
}

t_hit	*hit_cy(t_ray *ray, t_solution *res, t_cylinder *cy)
{
	t_hit		*hit;
	double		z1;
	double		z2;

	hit = hit_cy_create(0, 0, cy);
	hit->t1 = (-res->b - sqrt(res->b * res->b - 4 * res->a * res->c))
		/ (2 * res->a);
	hit->t2 = (-res->b + sqrt(res->b * res->b - 4 * res->a * res->c))
		/ (2 * res->a);
	ray->dir = tuple_normalize_f(ray->dir, free);
	z1 = ray->origin->y + hit->t1 * ray->dir->y;
	z2 = ray->origin->y + hit->t2 * ray->dir->y;
	if (hit->t1 > 0.0f && z1 > 0.01f && z1 < cy->height)
		hit->hitpoint = ray_at(ray, hit->t1);
	else if (hit->t2 > 0.0f && z2 > 0.01f && z2 < cy->height)
		hit->hitpoint = ray_at(ray, hit->t2);
	else
	{
		free(hit->entity);
		free(hit);
		return (NULL);
	}
	hit->eyev = tuple_negate(ray->dir);
	hit->norm = normal_at_cy(cy, hit->hitpoint, 0);
	return (hit);
}

void	free_res_ray(t_ray *ray, t_solution *r)
{
	free(r);
	ray_delete(ray);
}

t_hit	*ray_cy_hit(t_ray *ray, t_cylinder *cy)
{
	t_hit		*hit;
	t_solution	*res;

	res = ft_calloc(1, sizeof(t_solution));
	ray = ray_transform(ray, cy->inv_transform, NULL, NULL);
	res->a = pow(ray->dir->x, 2) + pow(ray->dir->z, 2);
	if (res->a <= 0.0f)
	{
		free_res_ray(ray, res);
		return (NULL);
	}
	res->b = 2.0f * ray->origin->x * ray->dir->x
		+ ray->origin->z * ray->dir->z * 2.0f;
	res->c = pow(ray->origin->x, 2) + pow(ray->origin->z, 2)
		- (cy->diameter * cy->diameter);
	if ((res->b * res->b - 4 * res->a * res->c) < 0)
	{
		free_res_ray(ray, res);
		return (NULL);
	}
	hit = hit_cy(ray, res, cy);
	free_res_ray(ray, res);
	return (hit);
}
