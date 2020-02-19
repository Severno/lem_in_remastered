/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:12:16 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 08:54:51 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			is_nan(long double float_num)
{
	return (float_num != float_num);
}

int			is_inf(long double float_num)
{
	if (float_num == -(1.0 / 0.0))
		return (2);
	else if (float_num == (1.0 / 0.0))
		return (1);
	else
		return (0);
}

int			is_value(long double float_num)
{
	if (is_inf(float_num) || is_nan(float_num))
		return (0);
	else
		return (1);
}

long double	round_float(int precision)
{
	long double rounder;

	rounder = 0.5;
	while (precision)
	{
		rounder /= 10;
		precision--;
	}
	return (rounder);
}
