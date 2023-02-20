/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:15:37 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/05 21:24:57 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "color.h"
# include "entity.h"
# include "hit.h"
# include "material.h"
# include "types.h"
# include <math.h>
# include <fcntl.h>
# include "matrix.h"
# include "point.h"
# include "ray.h"
# include "camera.h"
# include "tuple.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "vector.h"
# include "normals.h"
# include "utils.h"

void		free_tab(char **tab);
void		free_res_ray(t_ray *ray, t_solution *r);
int			handle_cam(char *file);
int			check_fields_comma(char *line, int nb);
int			error_management(char *file);
int			comma_check(char **tab, int nb);
void		error_print(void);
int			check_cam(char *line);
int			check_c(char *line, int fd);
int			check_a(char *line, int fd);
int			check_l(char *line, int fd);
int			check_element1(char *file);
char		**test_field(char **tab, int nb);
t_world		*parse_ambient(char *line, t_world *world);
t_world		*parse_cam(char *line, t_world *world);
t_world		*parse_light(char *line, t_world *world);
t_entity	*parse_cylinder(char *line);
t_entity	*parse_plane(char *line);
t_entity	*parse_sphere(char *line);
t_world		*parse_line(char *line, t_world *scene);
t_world		*parse_file(char *file, t_world *scene);
void		print_tuple(t_tuple *tpl);
void		*free_return(char **tab);
void		*return_error(void);
int			check_element1(char *file);
#endif