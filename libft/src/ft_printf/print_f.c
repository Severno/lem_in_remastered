/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:59:50 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 11:14:32 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*inf_nan_handle(long double float_num)
{
	char *inf_nan;

	if (float_num == -(1.0 / 0.0))
	{
		inf_nan = ft_strdup("-inf");
		return (inf_nan);
	}
	else if (float_num == (1.0 / 0.0))
	{
		inf_nan = ft_strdup("inf");
		return (inf_nan);
	}
	else if (float_num != float_num)
	{
		inf_nan = ft_strdup("nan");
		return (inf_nan);
	}
	return (NULL);
}

void		handle_width_float(t_param *param,
		long double value, char *float_val, int *flag)
{
	if (param->t_f.minus)
	{
		param->t_f.space && !is_nan(value) && is_inf(value) < 2
		? write(1, " ", 1) : 0;
		p_f_sign(value, flag, &param->bits, param);
		value < 0.0 ? pf_putstr(ft_strchr(float_val, '-') + 1, param)
		: pf_putstr(float_val, param);
		param->t_f.hash && param->precision == 0 ? write(1, ".", 1) : 0;
		fill_float_width(param, value, &param->bits);
	}
	else
	{
		param->t_f.space && !is_nan(value) && is_inf(value) < 2
		? write(1, " ", 1) : 0;
		fill_float_width(param, value, &param->bits);
		p_f_sign(value, flag, &param->bits, param);
		value < 0.0 ? pf_putstr(ft_strchr(float_val, '-') + 1, param)
		: pf_putstr(float_val, param);
		param->t_f.hash && param->precision == 0
		? write(1, ".", 1) : 0;
	}
}

void		print_f(t_param *param,
		long double value, char *float_val)
{
	t_ldbl_cast		fl_sign;
	int				flag;

	fl_sign.f = value;
	flag = 0;
	if (check_is_special(param, float_val, value))
		return ;
	if (fl_sign.t_ldbl_parts.sign == 1 && fl_sign.f == -0)
	{
		float_neg_zero(param, value, float_val);
		return ;
	}
	else if (fl_sign.t_ldbl_parts.sign == 0 && (int)value % 10 == 0)
	{
		float_pos_zero(param, value, float_val);
		return ;
	}
	if (param->t_f.minus)
		check_left_condition(param, value, float_val, &flag);
	else
		check_right_condition_float(param, value, float_val, &flag);
}
