/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_zeros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:44:01 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 19:58:57 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	p_float_zero_sign(t_param *param)
{
	if (param->t_f.plus)
	{
		write(1, "+", 1);
		param->bits++;
	}
}

static void	p_float_dot_sign(t_param *param)
{
	if (param->t_f.hash && param->precision == 0)
	{
		write(1, ".", 1);
		param->bits++;
	}
}

void		float_neg_zero(t_param *param, long double value, char *float_val)
{
	fill_float_width(param, value, &param->bits);
	param->bits += write(1, "-", 1);
	pf_putstr(float_val, param);
	p_float_dot_sign(param);
}

void		float_pos_zero(t_param *param, long double value, char *float_val)
{
	p_float_zero_sign(param);
	if (param->float_sign == 1)
		param->bits += write(1, "-", 1);
	param->t_f.space ? param->bits += write(1, " ", 1) : 0;
	fill_float_width(param, value, &param->bits);
	pf_putstr(float_val, param);
	p_float_dot_sign(param);
}
