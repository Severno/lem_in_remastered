/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:11:51 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 11:47:56 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		flag_f_support(t_param *param, char *flags,
		char *float_val, long double value)
{
	t_ldbl_cast		fl_sign;

	fl_sign.f = value;
	param->val_length = ft_strlen(float_val);
	remove_conflicted_flags(param, value);
	calc_reserved_float_fields(param, value, fl_sign.t_ldbl_parts.sign);
	calc_do_float_width(param);
	print_f(param, value, float_val);
	remove_current_flags(param, flags);
}

void			flag_f(t_param *param, long double value)
{
	char			*flags;
	char			*float_val;
	char			*nan_handle;

	flags = ft_strdup("Llf");
	float_val = NULL;
	if ((nan_handle = inf_nan_handle(value)) != NULL)
	{
		flag_f_support(param, flags, nan_handle, value);
		free(nan_handle);
		nan_handle = NULL;
	}
	else
	{
		float_val = ft_strnew(100);
		ft_ftoa(value, float_val, param->precision, 1);
		flag_f_support(param, flags, float_val, value);
		free(float_val);
		float_val = NULL;
	}
	free(flags);
	flags = NULL;
}
