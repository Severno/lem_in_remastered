/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:51:21 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:51:56 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	pf_putunbr(unsigned long long int nb, t_param *param)
{
	char c;

	c = '0';
	if (nb / 10 != 0)
		pf_putunbr(nb / 10, param);
	c = (char)(nb % 10 + '0');
	param->bits += write(1, &c, 1);
}
