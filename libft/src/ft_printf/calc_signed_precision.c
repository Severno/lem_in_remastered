/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_signed_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:39:56 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 15:40:01 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	get_do_precision(t_param *param)
{
	if (check_convention(param) == 0)
		param->do_precision = param->precision == -1 ? 0 : param->precision;
	else
		param->do_precision = param->precision - param->val_nums;
}
