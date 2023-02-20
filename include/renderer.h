/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:34:06 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/26 01:05:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "types.h"

t_image	*render(t_world *w, t_vue *vue);
t_list	*get_all_hits(t_list *objs, t_ray *ray);
#endif
