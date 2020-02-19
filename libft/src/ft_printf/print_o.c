/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:00:22 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 20:03:59 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		p_o_sign(t_param *param)
{
	if (param->t_f.plus)
	{
		write(1, "+", 1);
		param->bits++;
	}
}

static void		print_hash_zero(t_param *param)
{
	if (param->t_f.hash != 0 && param->precision <= param->val_length)
	{
		write(1, "0", 1);
		param->bits++;
	}
}

static void		zero_handle_o_right(t_param *param)
{
	if (param->t_f.zero)
	{
		p_o_sign(param);
		fill_width(param);
		fill_precision(param);
		return ;
	}
	fill_width(param);
	p_o_sign(param);
	print_hash_zero(param);
	fill_precision(param);
	if (param->t_f.hash == 0 && param->precision == -1)
		pf_putstr(ft_convert_undec_base_to_str(8,
				check_un_convention(param), 'x'), param);
}

static void		zero_handle_o(t_param *param)
{
	if (param->t_f.minus)
	{
		p_o_sign(param);
		print_hash_zero(param);
		fill_precision(param);
		if (param->t_f.hash == 0 && param->precision == -1)
			pf_putstr(ft_convert_undec_base_to_str(8,
					check_un_convention(param), 'x'), param);
		fill_width(param);
	}
	else
		zero_handle_o_right(param);
}

void			print_o(t_param *param, char *undec_base)
{
	if (param->un_value == 0)
	{
		zero_handle_o(param);
		return ;
	}
	p_o_sign(param);
	param->t_f.minus == 0 ? fill_width(param) : 0;
	fill_precision(param);
	print_hash_zero(param);
	pf_putstr(undec_base, param);
	param->t_f.minus == 1 ? fill_width(param) : 0;
}
