/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_unsigned_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:42:24 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 15:50:03 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		get_do_unwidth(t_param *param, unsigned long long value)
{
	if (value == 0)
	{
		if (pf_strchr(param->flags, '0'))
			param->do_width = param->precision == -1 ?
					param->width + param->res_fields :
					param->width - param->precision + param->res_fields;
		else
			param->do_width = param->precision == -1 ?
					param->width + param->res_fields - param->val_length :
					param->width - param->precision + param->res_fields;
	}
	else if (param->precision >= param->val_length)
	{
		param->do_width = param->width - param->precision + param->res_fields;
	}
	else
		param->do_width = param->width - param->val_length + param->res_fields;
}

static void	unreserved_o_u_check(t_param *param, int *res_fields,
		unsigned long long value)
{
	param->t_f.plus ? (*res_fields)-- : 0;
	param->t_f.space ? (*res_fields)-- : 0;
	if (param->t_f.hash && param->precision <= param->val_length
		&& param->precision == 0 && value == 0)
		(*res_fields)--;
	if (param->t_f.hash && param->precision <= param->val_length
		&& param->precision >= -1 && value != 0)
		(*res_fields)--;
}

void		calc_unreserved_fields(t_param *param, unsigned long long value)
{
	int res_fields;

	res_fields = 0;
	if ((pf_strchr("xX", param->current_flag) != 0))
	{
		param->t_f.plus ? res_fields-- : 0;
		param->t_f.space ? res_fields-- : 0;
		if (param->t_f.hash && param->precision >= -1 && value > 0)
			res_fields -= 2;
	}
	else if (param->current_flag == 'o' || param->current_flag == 'u')
		unreserved_o_u_check(param, &res_fields, value);
	else if (param->current_flag == 'p')
	{
		param->t_f.plus ? res_fields-- : 0;
		param->t_f.space ? res_fields-- : 0;
		res_fields -= 2;
	}
	param->res_fields = res_fields;
}
