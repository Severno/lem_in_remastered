/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sizet_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:22:09 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:22:09 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_print_sizet_arr(size_t *sizet_arr, int in_line, size_t size)
{
	size_t i;

	i = 0;
	if (in_line == 1)
		while (i < size)
			ft_printf("%lu ", sizet_arr[i++]);
	else if (in_line == 0)
		while (i < size)
			ft_printf("%lu\n", sizet_arr[i++]);
}
