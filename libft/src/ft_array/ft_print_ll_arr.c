/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ll_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:21:07 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:21:07 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_print_ll_arr(long long *ll_arr, int in_line, size_t size)
{
	size_t i;

	i = 0;
	if (in_line == 1)
		while (i < size)
			ft_printf("%lld ", ll_arr[i++]);
	else if (in_line == 0)
		while (i < size)
			ft_printf("%lld\n", ll_arr[i++]);
}
