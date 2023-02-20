/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:15:14 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:07:58 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "utils.h"
#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static double	absf(double n)
{
	if (n > 0.0f)
		return (n);
	return (-n);
}

t_bool	double_cmp(double a, double b)
{
	if (absf(a - b) < EPSILON)
		return (true);
	return (false);
}

int	ft_isdouble(char *src)
{
	int	i;
	int	decimal_point;

	i = 0;
	if (*src == '-')
		i++;
	decimal_point = 0;
	while (*(src + i) != '\0')
	{
		if (ft_isdigit(*(src + i)))
			;
		else if (decimal_point == 0 && *(src + i) == '.')
			decimal_point = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
