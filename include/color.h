/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:20:36 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "types.h"

t_color	*color_create(double red, double green, double blue);
int		create_trgb(int t, int r, int g, int b);
t_color	*hadamard_product(t_color *c1, t_color *c2);
t_color	*hadamard_product_f(t_color *c1, t_color *c2,
			void (*f1)(void *), void (*f2)(void *));
#endif
