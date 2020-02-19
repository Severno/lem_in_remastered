/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:04:49 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 17:05:08 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_percent(t_param *param)
{
	remove_unconflicted_flags(param);
	if (param->t_f.minus)
	{
		param->bits += write(1, "%", 1);
		fill_width(param);
	}
	else
	{
		fill_width(param);
		param->bits += write(1, "%", 1);
	}
}
