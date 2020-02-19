/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:10:39 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 10:19:40 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void			handle_flags(t_param *param, int *iter)
{
	param->str[*iter] == '0' && pf_strchr_flags(param->flags, '0', iter) == 0
	? pf_strcat(param->flags, "0", iter, param) : 0;
	param->str[*iter] == '#' && pf_strchr_flags(param->flags, '#', iter) == 0
	? pf_strcat(param->flags, "#", iter, param) : 0;
	param->str[*iter] == '-' && pf_strchr_flags(param->flags, '-', iter) == 0
	? pf_strcat(param->flags, "-", iter, param) : 0;
	param->str[*iter] == '+' && pf_strchr_flags(param->flags, '+', iter) == 0
	? pf_strcat(param->flags, "+", iter, param) : 0;
	param->str[*iter] == ' ' && pf_strchr_flags(param->flags, ' ', iter) == 0
	? pf_strcat(param->flags, " ", iter, param) : 0;
	param->str[*iter] == '\'' && pf_strchr_flags(param->flags, '\'', iter) == 0
	? pf_strcat(param->flags, "\'", iter, param) : 0;
	param->str[*iter] == '$' && pf_strchr_flags(param->flags, '$', iter) == 0
	? pf_strcat(param->flags, "$", iter, param) : 0;
	param->str[*iter] == '*' && pf_strchr_flags(param->flags, '*', iter) == 0
	? pf_strcat(param->flags, "*", iter, param) : 0;
}

static void			handle_convension(t_param *param, int *iter)
{
	param->str[*iter] == 'd' ? pf_strcat(param->flags, "d", iter, param) : 0;
	param->str[*iter] == 'D' ? pf_strcat(param->flags, "D", iter, param) : 0;
	param->str[*iter] == 'i' ? pf_strcat(param->flags, "i", iter, param) : 0;
	param->str[*iter] == 'u' ? pf_strcat(param->flags, "u", iter, param) : 0;
	param->str[*iter] == 'o' ? pf_strcat(param->flags, "o", iter, param) : 0;
	param->str[*iter] == 'x' ? pf_strcat(param->flags, "x", iter, param) : 0;
	param->str[*iter] == 'X' ? pf_strcat(param->flags, "X", iter, param) : 0;
	param->str[*iter] == 'c' ? pf_strcat(param->flags, "c", iter, param) : 0;
	param->str[*iter] == 's' ? pf_strcat(param->flags, "s", iter, param) : 0;
	param->str[*iter] == 'p' ? pf_strcat(param->flags, "p", iter, param) : 0;
	param->str[*iter] == 'f' ? pf_strcat(param->flags, "f", iter, param) : 0;
	param->str[*iter] == 'F' ? pf_strcat(param->flags, "F", iter, param) : 0;
	param->str[*iter] == 'L' ? pf_strcat(param->flags, "L", iter, param) : 0;
	param->str[*iter] == 'h' && param->str[(*iter) + 1] == 'h'
	? pf_strcat(param->flags, "hh", iter, param) : 0;
	param->str[*iter] == 'l' && param->str[(*iter) + 1] == 'l'
	? pf_strcat(param->flags, "ll", iter, param) : 0;
	param->str[*iter] == 'h' ? pf_strcat(param->flags, "h", iter, param) : 0;
	param->str[*iter] == 'l' ? pf_strcat(param->flags, "l", iter, param) : 0;
	if (pf_strchr("123456789.", param->str[*iter]))
		flag_width(param, iter);
}

static int			handle_exceptions(t_param *param, int *iter)
{
	if (param->str[*iter] == '\0')
	{
		param->iter = *iter;
		return (1);
	}
	if (!pf_strchr("DdiouxXegscpfF%123456789.hlL*-0#+ $*", param->str[*iter]))
	{
		param->iter = --(*iter);
		return (1);
	}
	return (0);
}

static int			handle_unusual_flags(t_param *param, int *iter)
{
	int length;

	length = ft_strlen(param->flags);
	if (param->str[*iter] == '\0')
		return (1);
	if (pf_strchr("DdiouxXegscpfF%", param->str[*iter]))
		param->current_flag = param->str[*iter];
	param->flags[length] = (char)param->current_flag;
	if (ft_strstr(param->flags, "Lf"))
		param->ld_value = va_arg(param->args, long double);
	else if (ft_strstr(param->flags, "lf"))
		param->ld_value = va_arg(param->args, double);
	else if (param->current_flag == 'f' || param->current_flag == 'F')
		param->d_value = va_arg(param->args, double);
	else if ((param->current_flag != '%'))
		param->arg_value = va_arg(param->args, void *);
	param->iter = *iter;
	return (0);
}

void				get_flags(t_param *param)
{
	int iter;
	int size;

	iter = param->iter;
	size = 10;
	param->flags = (char*)ft_strnew(size);
	while ((param->current_flag = pf_strchr(
			"DdiouxXegscpfF%", param->str[iter])) == 0)
	{
		handle_convension(param, &iter);
		handle_flags(param, &iter);
		if (handle_exceptions(param, &iter))
			return ;
	}
	if (handle_unusual_flags(param, &iter))
		return ;
}
