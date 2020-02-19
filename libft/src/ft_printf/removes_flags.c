/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removes_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:11:21 by sapril            #+#    #+#             */
/*   Updated: 2019/12/02 08:05:19 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		remove_conflicted_flags(t_param *param, long double value)
{
	char *tmp;

	if (param->t_f.zero && param->t_f.minus)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '0');
		param->t_f.zero = 0;
		free(tmp);
		tmp = NULL;
	}
	if ((ft_strstr(param->flags, " ")) && ((ft_strstr(param->flags, "+")
			|| check_convention(param) < 0
			|| value < 0)))
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, ' ');
		param->t_f.space = 0;
		free(tmp);
		tmp = NULL;
	}
}

void		remove_unconflicted_flags(t_param *param)
{
	char *tmp;

	if (param->t_f.zero && param->t_f.minus)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '0');
		param->t_f.zero = 0;
		free(tmp);
		tmp = NULL;
	}
	if (param->t_f.space && param->t_f.plus)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, ' ');
		param->t_f.space = 0;
		free(tmp);
		tmp = NULL;
	}
}

void		remove_current_flags(t_param *param, char *flags)
{
	int		i;
	char	*remove_char;

	i = 0;
	remove_char = NULL;
	while (flags[i])
	{
		remove_char = ft_find_and_remove_char(param->flags, flags[i++]);
		free(remove_char);
		remove_char = NULL;
	}
}
