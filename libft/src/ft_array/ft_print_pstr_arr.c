/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pstr_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:33:15 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:21:44 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_print_pstr_arr(char **str, int in_line)
{
	size_t i;

	i = 0;
	if (in_line == 1)
	{
		while (str[i])
		{
			ft_putstr(str[i++]);
			ft_putchar(' ');
		}
	}
	else
	{
		while (str[i])
		{
			ft_putstr(str[i++]);
			ft_putchar('\n');
		}
	}
}
