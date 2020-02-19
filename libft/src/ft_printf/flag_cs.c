/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:59:27 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:02:42 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		calc_str_pres(t_param *param)
{
	if (param->precision > 0 && param->precision < param->val_length)
		param->do_precision = param->precision;
	else if (param->precision > 0 && param->precision >= param->val_length)
		param->do_precision = param->val_length;
	else if (param->precision == -1)
		param->do_precision = param->val_length;
	else if (param->precision == 0)
		param->do_precision = param->precision;
}

static void		calc_str_width(t_param *param)
{
	if (param->width >= param->val_length)
	{
		if (param->precision > 0 && param->precision < param->val_length)
			param->do_width = param->width - param->precision;
		else if (param->precision > 0 && param->precision >= param->val_length)
			param->do_width = param->width - param->val_length;
		else if (param->precision == -1)
			param->do_width = param->width - param->val_length;
		else if (param->precision == 0)
			param->do_width = param->width;
		else
			param->do_width = 0;
	}
	else if (param->width < param->val_length &&
	param->precision < param->val_length)
	{
		if (param->precision == -1)
			param->do_width = param->width - param->val_length;
		else
			param->do_width = param->width - param->precision;
	}
	else
		param->do_width = 0;
}

static void		print_str(t_param *param)
{
	int		i;
	char	*str;

	i = 0;
	str = param->str_value;
	if (param->t_f.minus)
	{
		while (i < param->do_precision)
			param->bits += write(1, &str[i++], 1);
		fill_width(param);
	}
	else
	{
		fill_width(param);
		while (i < param->do_precision)
			param->bits += write(1, &str[i++], 1);
	}
}

void			flag_str(t_param *param)
{
	char	flags[1];

	flags[0] = 's';
	param->str_value = param->arg_value != NULL
			? (char *)param->arg_value
			: "(null)";
	param->val_length = ft_strlen(param->str_value);
	remove_conflicted_flags(param, (int)param->str_value);
	calc_str_pres(param);
	calc_str_width(param);
	print_str(param);
	remove_current_flags(param, flags);
}

void			flag_char(t_param *param)
{
	char flags[1];
	char c;

	flags[0] = 'c';
	param->val_length = 1;
	param->do_width = param->width - param->val_length;
	remove_conflicted_flags(param, (char)param->arg_value);
	if (param->t_f.minus)
	{
		c = (char)param->arg_value;
		param->bits += write(1, &c, 1);
		fill_width(param);
	}
	else
	{
		fill_width(param);
		c = (char)param->arg_value;
		param->bits += write(1, &c, 1);
	}
	remove_current_flags(param, flags);
}
