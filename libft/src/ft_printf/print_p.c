/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:04:07 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 17:04:27 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_p(t_param *param, unsigned long long value,
		char *undec_base)
{
	param->t_f.minus == 0 ? fill_width(param) : 0;
	pf_putstr("0x", param);
	fill_precision(param);
	if (value > 0)
		pf_putstr(undec_base, param);
	else if (value == 0 && param->precision == -1)
		param->bits += write(1, "0", 1);
	param->t_f.minus == 1 ? fill_width(param) : 0;
}
