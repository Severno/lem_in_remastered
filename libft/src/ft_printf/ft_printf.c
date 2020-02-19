/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:26:42 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 09:58:36 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		free_vars(t_param *param)
{
	if (param->flags != NULL)
	{
		free(param->flags);
		param->flags = NULL;
	}
}

static void		param_init(t_param *param)
{
	param->flags = NULL;
	param->t_f.hash = 0;
	param->t_f.minus = 0;
	param->t_f.zero = 0;
	param->t_f.plus = 0;
	param->t_f.space = 0;
	param->t_f.percent = 0;
	param->value = 0;
	param->d_value = 0;
	param->ld_value = 0;
	param->un_value = 0;
	param->res_fields = 0;
	param->current_flag = '~';
	param->width = -1;
	param->precision = -1;
	param->val_length = 0;
	param->val_nums = 0;
	param->do_precision = 0;
	param->do_width = 0;
	param->float_sign = -1;
}

static void		check_condition(t_param *param)
{
	if (param->str[param->iter] == '%')
	{
		free_vars(param);
		param_init(param);
		param->iter += 1;
		get_flags(param);
		parse_flag(param);
	}
	else
	{
		write(1, &param->str[param->iter], 1);
		param->bits++;
	}
	param->iter++;
}

int				ft_printf(char *input, ...)
{
	t_param	*param;
	int		bits;
	size_t	input_len;

	param = (t_param*)ft_memalloc(sizeof(t_param));
	param->str = input;
	param->iter = 0;
	param->bits = 0;
	input_len = ft_strlen(input);
	va_start(param->args, input);
	while (param->str[param->iter] && (size_t)param->iter < input_len)
		check_condition(param);
	va_end(param->args);
	bits = param->bits;
	free_vars(param);
	free(param);
	param = NULL;
	return (bits);
}
