/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:15:40 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "defs.h"
# include "parsing/parser.h"
# include "types.h"

t_bool			double_cmp(double a, double b);
int				ft_strcmp(char *s1, char *s2);
int				ft_isdouble(char *src);
double			ft_atof(char *str);
double		deg_to_rad(double deg);
#endif // DEBUG
