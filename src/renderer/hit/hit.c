/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:09:10 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "math.h"

/**
 * take a list of hit and returns the closest one
 */

double	which_positive_and_low(double a, double b)
{
	if (a >= 0.0f && a < b)
		return (a);
	return (b);
}

t_hit	*which_is_close_to_cam(t_hit *low, t_hit *curr)
{
	if (curr->t1 < 0.0f && curr->t2 < 0.0f)
		return (low);
	if (curr->t1 >= 0.0f)
	{
		if (!low)
			return (curr);
		if (which_positive_and_low(low->t1, low->t2) > curr->t1)
			return (curr);
	}
	else
	{
		if (!low)
			return (curr);
		if (which_positive_and_low(low->t1, low->t2) > curr->t2)
			return (curr);
	}
	return (low);
}

t_hit	*hit(t_list *lst)
{
	t_hit	*low;
	t_hit	*curr;

	low = 0;
	while (lst)
	{
		curr = lst->content;
		low = which_is_close_to_cam(low, curr);
		lst = lst->next;
	}
	return (low);
}

// t_hit *hit(t_list *lst)
// {
// 	t_hit *low;
// 	t_hit *curr;

// 	low = NULL;
// 	while (lst)
// 	{
// 		curr = lst->content;
// 		if (curr->t1 < 0.0f && curr->t2 < 0.0f)
// 		{
// 			lst = lst->next;
// 			continue;
// 		}
// 		if (curr->t1 >= 0.0f)
// 		{
// 			if (low)
// 			{
// 				if (low->t1 > curr->t1)
// 					low = curr;
// 			}
// 			else
// 				low = curr;
// 		}
// 		if (curr->t2 >= 0.0f)
// 		{
// 			if (low)
// 			{
// 				if (low->t1 > curr->t2)
// 					low = curr;
// 			}
// 			else
// 				low = curr;
// 		}
// 		lst = lst->next;
// 	}
// 	return (low);
// }
