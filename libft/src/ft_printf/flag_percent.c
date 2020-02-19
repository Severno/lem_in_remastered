/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:16:15 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:16:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	calc_percent_width(t_param *param)
{
	param->do_width = param->width - 1;
}

void		flag_percent(t_param *param)
{
	char *flags;

	flags = ft_strdup("%");
	calc_percent_width(param);
	print_percent(param);
	remove_current_flags(param, flags);
	free(flags);
	flags = NULL;
}
