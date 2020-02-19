/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:52:29 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:52:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	fill_flags_in_struct(char flag, t_param *param)
{
	if (flag == '0')
		param->t_f.zero = 1;
	if (flag == '#')
		param->t_f.hash = 1;
	if (flag == '-')
		param->t_f.minus = 1;
	if (flag == '+')
		param->t_f.plus = 1;
	if (flag == ' ')
		param->t_f.space = 1;
	if (flag == '%')
		param->t_f.percent = 1;
}

char		*pf_strcat(char *s1, const char *s2, int *iter, t_param *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fill_flags_in_struct(s2[0], param);
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i++] = s2[j++];
		*iter += 1;
	}
	s1[i] = '\0';
	return (s1);
}
