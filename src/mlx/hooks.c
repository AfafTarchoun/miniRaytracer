/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:40 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/04 21:39:47 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks.h"
#include "parsing/parser.h"

int	key_hook(int keycode)
{
	if (keycode == 53)
	{
		printf("Exit\n");
		exit(0);
	}
	return (0);
}

int	x_exit(int keycode)
{
	(void) keycode;
	printf("Exit\n");
	exit(0);
}
