/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:59:16 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:08:47 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		flag_d(t_param *param)
{
	char *flags;

	flags = ft_strdup("llhhdDi");
	param->value = check_convention(param);
	param->val_length = ft_num_of_fields(param->value);
	param->val_nums = (int)ft_num_of_digits(param->value);
	remove_conflicted_flags(param, param->value);
	calc_reserved_fields(param, param->value);
	get_do_precision(param);
	get_do_width(param, param->value);
	print(param);
	remove_current_flags(param, flags);
	free(flags);
	flags = NULL;
}
