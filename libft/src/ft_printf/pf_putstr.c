/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:50:40 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:50:41 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	pf_putstr(char const *s, t_param *param)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	if (s)
	{
		ret = 0;
		while (s[i] && (ret = write(1, &s[i++], 1)))
			param->bits++;
	}
}
