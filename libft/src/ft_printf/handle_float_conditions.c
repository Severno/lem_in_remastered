/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_conditions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:20:35 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 21:54:14 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		p_f_sign(long double value,
							int *flag, int *bits, t_param *param)
{
	if (value < 0 && (*flag) == 0)
	{
		write(1, "-", 1);
		(*bits)++;
		*flag = 1;
	}
	else if (param->t_f.plus && (*flag) == 0)
	{
		write(1, "+", 1);
		(*bits)++;
		*flag = 1;
	}
}

void		handle_zero_fill_float(t_param *param,
		long double value, char *float_val, int *flag)
{
	if (param->t_f.minus)
	{
		param->t_f.space && !is_nan(value) && is_inf(value) < 2
		? write(1, " ", 1) : 0;
		p_f_sign(value, flag, &param->bits, param);
		value < 0.0 ? pf_putstr(ft_strchr(float_val, '-') + 1, param)
					: pf_putstr(float_val, param);
		fill_float_width(param, value, &param->bits);
		param->t_f.hash && param->precision == 0 ? write(1, ".", 1) : 0;
	}
	else
	{
		param->t_f.space && !is_nan(value) && is_inf(value) < 2
		? write(1, " ", 1) : 0;
		p_f_sign(value, flag, &param->bits, param);
		param->t_f.minus == 0
		? fill_float_width(param, value, &param->bits) : 0;
		value < 0.0 ? pf_putstr(ft_strchr(float_val, '-') + 1, param)
					: pf_putstr(float_val, param);
		param->t_f.minus ? fill_float_width(param, value, &param->bits) : 0;
		param->t_f.hash && param->precision == 0 ? write(1, ".", 1) : 0;
	}
}

void		check_left_condition(t_param *param,
		long double value, char *float_val, int *flag)
{
	if (param->t_f.zero)
		handle_zero_fill_float(param, value, float_val, flag);
	else
		handle_width_float(param, value, float_val, flag);
}

void		check_right_condition_float(t_param *param,
		long double value, char *float_val, int *flag)
{
	if (param->t_f.zero)
		handle_zero_fill_float(param, value, float_val, flag);
	else
		handle_width_float(param, value, float_val, flag);
}

int			check_is_special(t_param *param,
		char *float_val, long double value)
{
	if (ft_strequ(float_val, "nan")
		|| ft_strequ(float_val, "-nan")
		|| ft_strequ(float_val, "inf")
		|| ft_strequ(float_val, "-inf"))
	{
		param->t_f.minus == 0
		? fill_float_width(param, value, &param->bits) : 0;
		param->t_f.plus && !ft_strequ(float_val, "nan")
		? param->bits += write(1, "+", 1) : 0;
		pf_putstr(float_val, param);
		param->t_f.minus
		? fill_float_width(param, value, &param->bits) : 0;
		return (1);
	}
	return (0);
}
