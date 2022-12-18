/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:52:15 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/18 08:25:15 by atarchou         ###   ########.fr       */
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

void material(t_material *m)
{
  m->ambient = 0.1;
  m->deffuse = 0.9;
  m->specular = 0.9;
  m->shininess = 200.0;
}
// t_color *lighting(t_material *m,t_world *world, t_vector *point, t_vector *eye, t_vector *n)
t_color *lighting(t_material *m, t_world *world, t_point *point, t_vector *N)
{
    t_color *eff_color;
    t_color *ambient;
    t_color *diffuse;
    t_color *specular;
    t_vector *lightv;
    t_vector *reflectv;
    double light_dot_normal;
    double reflect_dot_normal;
    double factor;
    
    eff_color = multiply(m->color,world->light->intensity);
    lightv = tuple_normalize(tuple_sub(world->light->pos, point));
    ambient = multiply(eff_color, m->ambient);
    light_dot_normal = tuple_dot(lightv, N);
    if (light_dot_normal < 0)
    {
        diffuse = 0;
        specular = 0;
    }
    else
    {        
        diffuse = multiply(multiply(eff_color, m->deffuse), light_dot_normal);
        // reflectv = reflect(tuple_negate(lightv), N);
        // reflect_dot_normal = tuple_dot(reflectv, world->camera->origin);
        // if (reflect_dot_normal <= 0)
        //     specular = 0;
        // else
        // {
        //   factor = pow(reflect_dot_normal, m->shininess);
        //   // specular = factor * m->specular * world->light->intensity;
        // }
    }
    return (tuple_add(diffuse, ambient));
}
