/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:15:37 by atarchou          #+#    #+#             */
/*   Updated: 2022/12/15 05:35:14 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
#define PARSER_H
#include "../color.h"
#include "../entity.h"
#include "../hit.h"
#include "../material.h"
#include "../types.h"
#include <math.h>
#include <fcntl.h>
#include "../matrix.h"
#include "../point.h"
#include "../ray.h"
#include "../camera.h"
#include "../tuple.h"
#include "../../libs/gnl/get_next_line.h"
#include "../../libs/libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../vector.h"

void free_tab(char **tab);
int	handle_cam(char *file);
int check_fields_comma(char *line, int nb);
int error_management(char *file);
t_world *parse_ambient(char *line, t_world *world);
t_world *parse_cam(char *line, t_world *world);
t_world *parse_light(char *line, t_world *world);
t_entity *parse_cylinder(char *line);
t_entity *parse_plane(char *line);
t_entity *parse_sphere(char *line);
t_world *parse_line(char *line, t_world *scene);
t_hit *ray_cy_hit(t_ray *ray, t_cylinder *cy);
t_hit *ray_pl_hit(t_ray *ray,  t_plane *pl);
t_vector *reflect(t_vector *in, t_vector *normal);
t_color *lighting(t_sphere *sp, t_world *world, t_point *point);
t_tuple *multiplyy(t_tuple *v, float m);
void print_tuple(t_tuple *tpl);
#endif