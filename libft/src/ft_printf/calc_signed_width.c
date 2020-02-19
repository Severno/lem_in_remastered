/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_signed_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:41:42 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 15:41:43 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		get_do_width(t_param *param, long long int value)
{
	if (value == 0)
		param->do_width = param->precision == -1 ?
				param->width + param->res_fields - param->val_nums :
				param->width - param->precision + param->res_fields;
	else if (param->precision >= param->val_nums)
		param->do_width = param->width - param->precision +
				param->res_fields;
	else
		param->do_width = param->width - param->val_nums +
				param->res_fields;
}

void		calc_reserved_fields(t_param *param, long long int value)
{
	int		res_fields;
	char	*tmp;

	res_fields = 0;
	if ((ft_strstr(param->flags, "+")) && value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		param->t_f.plus = 0;
		free(tmp);
		tmp = NULL;
	}
	if (value >= 0)
	{
		pf_strchr(param->flags, '+') ? res_fields-- : 0;
		pf_strchr(param->flags, ' ') ? res_fields-- : 0;
	}
	else
		value < 0 ? res_fields -= 1 : 0;
	param->res_fields = res_fields;
}
