/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:42:38 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 21:39:15 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void			parse_flag_add(t_param *param)
{
	ft_strstr(param->flags, "llo") ? flag_o(param) : 0;
	ft_strstr(param->flags, "lo") ? flag_o(param) : 0;
	ft_strstr(param->flags, "hho") ? flag_o(param) : 0;
	ft_strstr(param->flags, "ho") ? flag_o(param) : 0;
	ft_strstr(param->flags, "o") ? flag_o(param) : 0;
	ft_strstr(param->flags, "llx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "lx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hhx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "x") ? flag_x(param) : 0;
	ft_strstr(param->flags, "llX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "lX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hhX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "X") ? flag_x(param) : 0;
	ft_strstr(param->flags, "c") ? flag_char(param) : 0;
	ft_strstr(param->flags, "s") ? flag_str(param) : 0;
	ft_strstr(param->flags, "p") ? flag_p(param) : 0;
	ft_strstr(param->flags, "Lf") ? flag_f(param, param->ld_value) : 0;
	ft_strstr(param->flags, "lf") ? flag_f(param, param->ld_value) : 0;
	ft_strstr(param->flags, "f") ? flag_f(param, param->d_value) : 0;
	ft_strstr(param->flags, "F") ? flag_f(param, param->d_value) : 0;
	ft_strstr(param->flags, "%") ? flag_percent(param) : 0;
}

void				parse_flag(t_param *param)
{
	if (param->str[param->iter] == '\0')
		return ;
	ft_strstr(param->flags, "lld") ? flag_d(param) : 0;
	ft_strstr(param->flags, "ld") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hhd") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hd") ? flag_d(param) : 0;
	ft_strstr(param->flags, "d") ? flag_d(param) : 0;
	ft_strstr(param->flags, "D") ? flag_d(param) : 0;
	ft_strstr(param->flags, "lli") ? flag_d(param) : 0;
	ft_strstr(param->flags, "li") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hhi") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hi") ? flag_d(param) : 0;
	ft_strstr(param->flags, "i") ? flag_d(param) : 0;
	ft_strstr(param->flags, "llu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "lu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "hhu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "hu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "u") ? flag_u(param) : 0;
	parse_flag_add(param);
}
