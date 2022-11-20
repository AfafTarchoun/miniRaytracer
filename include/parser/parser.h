/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:42:05 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/20 15:01:13 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdio.h>
# include "../../libs/gnl/get_next_line.h"
# include <fcntl.h>

t_scene *parse_file(char *file, t_scene *scene);
#endif