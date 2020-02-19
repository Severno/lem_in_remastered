/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:15:22 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 09:15:55 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flag_p(t_param *param)
{
	char *flags;
	char *undec_base;

	flags = ft_strdup("p");
	undec_base = ft_convert_undec_base_to_str(16,
			check_un_convention(param), 'x');
	param->un_value = check_un_convention(param);
	param->val_length = ft_strlen(undec_base);
	remove_conflicted_flags(param, param->un_value);
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_p(param, param->un_value, undec_base);
	remove_current_flags(param, flags);
	free(flags);
	free(undec_base);
	undec_base = NULL;
	flags = NULL;
}
