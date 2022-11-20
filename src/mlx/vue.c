/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vue.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:40 by habouiba          #+#    #+#             */
/*   Updated: 2022/08/19 18:31:42 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vue.h"

t_vue	*vue_init(void)
{
	t_vue	*vue;

	vue = ft_calloc(1, sizeof(t_vue));
	if (NOT vue)
	{
		perror("Error: ");
		return (NULL);
	}
	vue->mlx = mlx_init();
	if (NOT vue->mlx)
	{
		ft_putstr_fd("Error: could not open mlx object\n", 2);
		return (NULL);
	}
	vue->window = mlx_new_window(vue->mlx, VUE_WIDTH, VUE_HEIGHT, TITLE);
	if (NOT vue->window)
	{
		ft_putstr_fd("Error: could not create new window\n", 2);
		return (NULL);
	}
	return (vue);
}
