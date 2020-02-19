/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:07:02 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 09:26:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		print_hash_zero(t_param *param,
		unsigned long long value, char l_case, int *flag)
{
	if (param->t_f.hash != 0 && *flag == 0)
	{
		if (value > 0)
		{
			if (l_case == 'x')
				pf_putstr("0x", param);
			else
				pf_putstr("0X", param);
			*flag = 1;
		}
	}
}

static void		zero_handle_x_rigth_align(t_param *param,
		unsigned long long value, char l_case, int *flag)
{
	if (param->t_f.zero)
	{
		fill_width(param);
		fill_precision(param);
		return ;
	}
	print_hash_zero(param, value, l_case, flag);
	fill_width(param);
	fill_precision(param);
	if (param->t_f.hash == 0 && param->precision < 0)
		pf_putstr(ft_convert_undec_base_to_str(16, value, l_case), param);
	else if (param->t_f.hash != 0 && param->precision < 0)
		pf_putstr(ft_convert_undec_base_to_str(16, value, l_case), param);
}

static void		zero_handle_x(t_param *param,
		unsigned long long value, char l_case, int *flag)
{
	if (param->t_f.minus)
	{
		print_hash_zero(param, value, l_case, flag);
		fill_precision(param);
		if (param->t_f.hash == 0 && param->precision < 0)
			pf_putstr(ft_convert_undec_base_to_str(16, value, l_case), param);
		else if (param->t_f.hash != 0 && param->precision < 0)
			pf_putstr(ft_convert_undec_base_to_str(16, value, l_case), param);
		fill_width(param);
	}
	else
		zero_handle_x_rigth_align(param, value, l_case, flag);
}

void			print_x(t_param *param, unsigned long long value,
		char l_case, char *undec_base)
{
	int flag;

	flag = 0;
	if (param->un_value == 0)
	{
		zero_handle_x(param, value, l_case, &flag);
		return ;
	}
	if (param->t_f.minus)
	{
		print_hash_zero(param, value, l_case, &flag);
		fill_precision(param);
		pf_putstr(undec_base, param);
		fill_width(param);
	}
	else
	{
		param->t_f.zero && param->precision == -1 ?
		print_hash_zero(param, value, l_case, &flag) : 0;
		fill_width(param);
		print_hash_zero(param, value, l_case, &flag);
		fill_precision(param);
		pf_putstr(undec_base, param);
	}
}
