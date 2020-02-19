/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:05:23 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 17:06:15 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		print_hash_zero(t_param *param)
{
	if (param->t_f.hash != 0 && param->precision <= param->val_length)
		param->bits += write(1, "0", 1);
}

static void		zero_handle_u(t_param *param, unsigned long long value)
{
	if (param->t_f.minus)
	{
		print_hash_zero(param);
		fill_precision(param);
		if (param->t_f.hash == 0 && param->precision == -1)
			pf_putunbr(value, param);
		fill_width(param);
	}
	else
	{
		if (param->t_f.zero)
		{
			fill_width(param);
			fill_precision(param);
			return ;
		}
		fill_width(param);
		print_hash_zero(param);
		if (param->t_f.hash == 0 && param->precision == -1)
			pf_putunbr(value, param);
		fill_precision(param);
	}
}

static void		handle_right_condition(t_param *param, unsigned long long value)
{
	if (param->t_f.zero)
	{
		fill_width(param);
		fill_precision(param);
		pf_putunbr(value, param);
		return ;
	}
	fill_width(param);
	print_hash_zero(param);
	fill_precision(param);
	pf_putunbr(value, param);
}

void			print_u(t_param *param, unsigned long long value)
{
	if (value == 0)
	{
		zero_handle_u(param, value);
		return ;
	}
	if (param->t_f.minus)
	{
		print_hash_zero(param);
		fill_precision(param);
		pf_putunbr(value, param);
		fill_width(param);
	}
	else
		handle_right_condition(param, value);
}
