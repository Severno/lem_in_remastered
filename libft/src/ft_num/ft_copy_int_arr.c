/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_int_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:14:46 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 15:14:46 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		*ft_copy_int_arr(int *arr, size_t size)
{
	size_t	i;
	int		*arr_cpy;

	i = 0;
	if (!(arr_cpy = (int *)ft_memalloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		arr_cpy[i] = arr[i];
		i++;
	}
	return (arr_cpy);
}
