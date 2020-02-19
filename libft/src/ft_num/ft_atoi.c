/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:57:01 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:48:18 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	sum_long;

	i = 0;
	sign = 1;
	sum_long = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		sum_long = sum_long * 10 + (str[i++] - '0');
	if (sum_long >= MAX_LONG && sign == 1)
		return (-1);
	else if (sum_long >= MAX_LONG && sign == -1)
		return (0);
	return ((int)sum_long * sign);
}
