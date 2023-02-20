/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:29:04 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "utils.h"
#include "libft.h"

double	parse_double(char *str, int *i)
{
	double	val;
	double	fraction;

	val = 0;
	fraction = 0.1;
	while (ft_isdigit(str[*i]))
	{
		val = val * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			val += fraction * (str[*i] - '0');
			fraction /= 10;
			(*i)++;
		}
	}
	return (val);
}

int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		else
			sign = 1;
		(*i)++;
	}
	return (sign);
}

double	parse_exponent(char *str, int *i)
{
	int	exponent;
	int	exp_sign;

	exponent = 0;
	exp_sign = 1;
	if (str[*i] == 'e' || str[*i] == 'E')
	{
		(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
		{
			if (str[*i] == '-')
				exp_sign = -1;
			else
				exp_sign = 1;
			(*i)++;
		}
		while (ft_isdigit(str[*i]))
		{
			exponent = exponent * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
	return (pow(10, exponent * exp_sign));
}

double	ft_atof(char *str)
{
	double	val;
	int		i;
	int		sign;

	i = 0;
	sign = parse_sign(str, &i);
	val = parse_double(str, &i);
	val *= parse_exponent(str, &i);
	return (sign * val);
}
