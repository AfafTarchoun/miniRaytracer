/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:11:19 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/05 15:37:26 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

# include "types.h"

t_vector	*reflect(t_vector *in, t_vector *normal);
t_vector	*reflect_f(t_vector *in, t_vector *normal,
				void (*f1)(void *), void (*f2)(void *));
#endif // !REFLECTION_H
