/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:52:15 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 01:40:15 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "light.h"
#include "reflection.h"

t_color	*specular(t_lighting *lighting, t_world *w,
		t_material *m, double reflect_dot_eye)
{
	if (reflect_dot_eye <= 0)
		lighting->specular = color_create(0, 0, 0);
	else
	{
		lighting->specular = tuple_scale(w->alight->material->color,
				(m->specular * pow(reflect_dot_eye, m->shininess)));
	}
	free(lighting->reflectv);
	return (lighting->specular);
}

t_color	*multiply_component(t_lighting *v)
{
	t_color	*result;

	result = tuple_add_f(v->ambient,
			tuple_add_f(v->diffuse, v->specular, free, free), free, free);
	free(v->effect);
	free(v->lightv);
	free(v);
	return (result);
}

t_color	*lighting(t_material *m, t_world *w, t_hit *hit, int in_shadow)
{
	t_lighting	*light;
	double		light_d;
	double		reflect_dot_eye;

	light = ft_calloc(1, sizeof(t_lighting));
	m->ambient = w->alight->ratio;
	light->effect = hadamard_product(m->color, w->alight->material->color);
	light->lightv = tuple_normalize_f(tuple_sub(w->light->pos,
				hit->hitpoint), free);
	light->ambient = tuple_scale(light->effect, m->ambient);
	light_d = tuple_dot(light->lightv, hit->norm);
	if (light_d < 0 || in_shadow)
	{
		light->diffuse = color_create(0, 0, 0);
		light->specular = color_create(0, 0, 0);
	}
	else
	{
		light->diffuse = tuple_scale(light->effect, (m->deffuse * light_d));
		light->reflectv = reflect_f(tuple_negate(light->lightv),
				hit->norm, free, NULL);
		reflect_dot_eye = tuple_dot(light->reflectv, hit->eyev);
		light->specular = specular(light, w, m, reflect_dot_eye);
	}
	return (multiply_component(light));
}
