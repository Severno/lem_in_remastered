/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_float_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:39:10 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 11:21:37 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		calc_reserved_float_fields(t_param *param,
		long double value, int sign)
{
	int		res_fields;
	char	*tmp;

	res_fields = 0;
	if (param->t_f.plus && value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		param->t_f.plus = 0;
		free(tmp);
		tmp = NULL;
	}
	if (value >= 0)
	{
		param->t_f.plus ? res_fields-- : 0;
		param->t_f.space ? res_fields-- : 0;
	}
	if (param->t_f.hash && param->precision == 0)
		res_fields--;
	if (sign == 1 && value == -0)
		res_fields--;
	param->res_fields = res_fields;
}

void		calc_reserved_lfloat_fields(t_param *param)
{
	int			res_fields;
	char		*tmp;

	res_fields = 0;
	if (param->t_f.plus && param->ld_value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		param->t_f.plus = 0;
		free(tmp);
		tmp = NULL;
	}
	if (param->ld_value >= 0)
	{
		param->t_f.plus ? res_fields-- : 0;
		param->t_f.space ? res_fields-- : 0;
	}
	if (param->t_f.hash && param->precision == 0)
		res_fields--;
	param->res_fields = res_fields;
}

void		calc_do_float_width(t_param *param)
{
	param->do_width = param->width - param->val_length + param->res_fields;
}
