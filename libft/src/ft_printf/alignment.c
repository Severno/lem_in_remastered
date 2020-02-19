/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:49:58 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 09:44:01 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		fill_width(t_param *param)
{
	if (param->t_f.percent && param->t_f.minus)
		fill(param->do_width, ' ', param);
	else if (param->t_f.zero && (param->precision == -1
	|| param->precision == 0))
		fill(param->do_width, '0', param);
	else
		fill(param->do_width, ' ', param);
}

void		fill_float_width(t_param *param, long double value, int *bits)
{
	if (is_inf(value))
		fill(param->do_width, ' ', param);
	else if (param->t_f.zero && is_value(value))
		fill_float(param->do_width, '0', param, bits);
	else
		fill_float(param->do_width, ' ', param, bits);
}

void		fill_float(int value, char sign, t_param *param, int *bits)
{
	(void)param;
	while (value > 0)
	{
		write(1, &sign, 1);
		(*bits)++;
		value--;
	}
}

void		fill_precision(t_param *param)
{
	fill(param->do_precision, '0', param);
}

void		fill(int value, char sign, t_param *param)
{
	char *removed_char;

	removed_char = NULL;
	if (pf_strchr(param->flags, ' ')
	&& pf_strchr(param->flags, 'c') == 0
	&& pf_strchr(param->flags, 'u') == 0
	&& pf_strchr(param->flags, '%') == 0)
	{
		write(1, " ", 1);
		param->bits++;
		removed_char = ft_find_and_remove_char(param->flags, ' ');
		param->t_f.space = 0;
	}
	while (value > 0)
	{
		write(1, &sign, 1);
		param->bits++;
		value--;
	}
	free(removed_char);
	removed_char = NULL;
}
