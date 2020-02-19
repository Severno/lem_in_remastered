/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_of_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 09:00:03 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 09:00:30 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_max_of_three(int a, int b, int c)
{
	if (a >= b && a > c)
		return (a);
	else if (b >= a && b > c)
		return (b);
	else if (c >= a && c > b)
		return (c);
	return (0);
}
