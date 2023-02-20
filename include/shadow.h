/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:16:52 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/06 22:15:28 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H
# include "types.h"

int	is_shadowed(t_world *world, t_vector *point);
int	is_shadowed_cy(t_world *world, t_vector *point);
#endif