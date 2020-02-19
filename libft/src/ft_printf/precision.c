/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:05:32 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:54:26 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		calc_width(t_param *param, int *iter)
{
	param->width = 0;
	while ((param->str[*iter] >= '0' && param->str[*iter] <= '9'))
		param->width = param->width * 10 + (param->str[(*iter)++] - '0');
}

static void		calc_precision(t_param *param, int *iter)
{
	param->precision = 0;
	while ((param->str[(*iter)] >= '0' && param->str[(*iter)] <= '9'))
		param->precision = param->precision * 10
				+ (param->str[(*iter)++] - '0');
}

void			flag_width(t_param *param, int *iter)
{
	if ((param->str[(*iter)] >= '0' && param->str[(*iter)] <= '9'))
		calc_width(param, iter);
	if (param->str[(*iter)] == '.')
	{
		*iter += 1;
		param->precision = 0;
	}
	if ((param->str[(*iter)] >= '0' && param->str[(*iter)] <= '9'))
		calc_precision(param, iter);
}
