/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vue.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:40 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/04 21:37:28 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vue.h"

t_vue	*vue_init(void)
{
	t_vue	*vue;

	vue = ft_calloc(1, sizeof(t_vue));
	if (!vue)
	{
		perror("Error: ");
		return (NULL);
	}
	vue->mlx = mlx_init();
	if (!vue->mlx)
	{
		ft_putstr_fd("Error: could not open mlx object\n", 2);
		return (NULL);
	}
	vue->window = mlx_new_window(vue->mlx, VUE_WIDTH, VUE_HEIGHT, TITLE);
	if (!vue->window)
	{
		ft_putstr_fd("Error: could not create new window\n", 2);
		return (NULL);
	}
	return (vue);
}
