/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:32:41 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:17:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flag_u(t_param *param)
{
	char *flags;

	flags = ft_strdup("llhhu");
	param->un_value = check_un_convention(param);
	param->val_length = ft_unnum_of_fields(param->un_value);
	remove_unconflicted_flags(param);
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_u(param, param->un_value);
	remove_current_flags(param, flags);
	free(flags);
	flags = NULL;
}
