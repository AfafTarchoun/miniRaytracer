/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:52:15 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/15 08:40:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing/parser.h"

t_light   *point_light(t_point *pos,double intense)
{
    t_light *light;
    
    light->pos = pos;
    light->intensity = intense;
    return (light);
}

t_tuple *multiplyy(t_tuple *v, float m)
{
    t_tuple *w;

    w = ft_calloc(1, sizeof(t_tuple));
    if (!w)
		return (w);
    w->x = v->x * m;
    w->y = v->y * m;
    w->z = v->z * m;
    return (w);
}

t_color *lighting(t_sphere *sp, t_world *world)
{
    // t_color *eff_color;
    // t_color *ambient;
    // t_color *diffuse;
    // t_color *specular;
    t_vector *lightv;
	t_vector *normal;
    // t_vector *reflectv;
    // double light_dot_normal;
    // double reflect_dot_normal;
    // double factor;
    normal = tuple_normalize(sp->hitpoint);
	normal = clamp_color(normal);
	normal = colooor(normal);
	lightv = tuple_normalize(world->light->pos);
	double d = tuple_dot(normal, tuple_negate(lightv));
    // printf("ehu\n");
    // eff_color = multiplyy(sp->material->color, world->light->intensity);
    // lightv = tuple_normalize(tuple_sub(world->light->pos, point));
    // ambient = multiplyy(eff_color, sp->material->ambient);
    // light_dot_normal = tuple_dot(lightv, sp->normal);
    // if (light_dot_normal < 0)
    // {
    //     diffuse = 0;
    //     specular = 0;
    // }
    // else
    // {        
    //     diffuse = multiplyy(multiplyy(eff_color, sp->material->deffuse), light_dot_normal);
    //     reflectv = reflect(tuple_negate(lightv), sp->normal);
    //     reflect_dot_normal = tuple_dot(reflectv, world->camera->origin);
    //     if (reflect_dot_normal <= 0)
    //         specular = 0;
    //     else
    //     {
    //         factor = pow(reflect_dot_normal, sp->material->shininess);
    //         // specular = factor * m->specular * world->light->intensity;
    //     }
    // }
    // return (tuple_add(diffuse, ambient));
    sp->material->color = multiplyy(sp->material->color, d);
    return(sp->material->color);
}
