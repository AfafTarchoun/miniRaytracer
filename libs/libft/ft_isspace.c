/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:49:37 by habouiba          #+#    #+#             */
/*   Updated: 2022/09/18 13:51:51 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace(int c) {
  if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
    return 1;
  return (0);
}
