/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:33:29 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 09:26:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flag_x(t_param *param)
{
	char l_case;
	char *flags;
	char *undec_base;

	flags = ft_strdup("llhhxX");
	l_case = param->current_flag == 'X' ? 'X' : 'x';
	param->un_value = check_un_convention(param);
	undec_base = ft_convert_undec_base_to_str(16,
			param->un_value, l_case);
	param->val_length = ft_strlen(undec_base);
	remove_unconflicted_flags(param);
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_x(param, param->un_value, l_case, undec_base);
	remove_current_flags(param, flags);
	free(flags);
	free(undec_base);
	undec_base = NULL;
	flags = NULL;
}
