/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:55:12 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:59:30 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		p_d_sign(t_param *param, int *flag, int *bits)
{
	if (param->value < 0 && (*flag) == 0)
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

static void		zero_handle(t_param *param, int *flag)
{
	if (param->t_f.minus)
	{
		p_d_sign(param, flag, &param->bits);
		fill_precision(param);
		param->precision == -1
		? pf_putnbr_base(param->value, 10, &(param->bits)) : 0;
		fill_width(param);
	}
	else
	{
		param->precision == -1 && param->t_f.zero
		? p_d_sign(param, flag, &param->bits) : 0;
		fill_width(param);
		p_d_sign(param, flag, &param->bits);
		fill_precision(param);
		param->precision == -1
		? pf_putnbr_base(param->value, 10, &(param->bits)) : 0;
	}
}

static void		right_align(t_param *param, int *flag)
{
	if (param->t_f.zero && param->precision == -1)
		p_d_sign(param, flag, &param->bits);
	fill_width(param);
	p_d_sign(param, flag, &param->bits);
	fill_precision(param);
	param->value < 0 ? pf_putunbr_base(param->value * -1, 10, &param->bits)
	: pf_putnbr_base(param->value, 10, &(param->bits));
}

static void		left_align(t_param *param, int *flag)
{
	p_d_sign(param, flag, &param->bits);
	fill_precision(param);
	param->value < 0 ? pf_putunbr_base(param->value * -1, 10, &param->bits)
	: pf_putnbr_base(param->value, 10, &(param->bits));
	fill_width(param);
}

void			print(t_param *param)
{
	int flag;

	flag = 0;
	if (param->value == 0)
	{
		zero_handle(param, &flag);
		return ;
	}
	if (param->t_f.minus)
		left_align(param, &flag);
	else
		right_align(param, &flag);
}
