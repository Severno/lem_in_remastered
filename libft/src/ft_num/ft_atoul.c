/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:45:21 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:48:18 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned long long	ft_atoul(const char *str)
{
	unsigned long long						i;
	uintmax_t								sum_long;

	i = 0;
	sum_long = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		sum_long = sum_long * 10 + (str[i++] - '0');
	return (sum_long);
}
