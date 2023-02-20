/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:29:46 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/05 22:14:24 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrix.h"

void	camera_delete(t_camera *c)
{
	free(c->orient);
	free(c->origin);
	matrix_free_4(c->transform);
	matrix_free_4(c->inv_transform);
	free(c);
}
