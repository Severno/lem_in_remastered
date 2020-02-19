/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_unsigned_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:41:57 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 15:42:04 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		get_do_unprecision(t_param *param, unsigned long long value)
{
	if (value == 0)
		param->do_precision = param->precision == -1 ? 0 : param->precision;
	else
		param->do_precision = param->precision - param->val_length;
}
