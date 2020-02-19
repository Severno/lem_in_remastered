/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:29:41 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 09:20:55 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flag_o(t_param *param)
{
	char *flags;
	char *undec_base;

	flags = ft_strdup("hhllo");
	undec_base = ft_convert_undec_base_to_str(8,
			check_un_convention(param), 'x');
	param->un_value = ft_atoul(undec_base);
	param->val_length = ft_unnum_of_fields(param->un_value);
	remove_unconflicted_flags(param);
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_o(param, undec_base);
	remove_current_flags(param, flags);
	free(flags);
	free(undec_base);
	undec_base = NULL;
	flags = NULL;
}
