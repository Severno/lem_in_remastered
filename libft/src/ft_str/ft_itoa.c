/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:44:19 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:48:18 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*ft_itoa(int num)
{
	char			*str;
	int				length;
	unsigned int	n_tmp;

	length = ft_num_of_digits(num);
	n_tmp = num;
	if (num < 0)
	{
		n_tmp *= -1;
		length++;
	}
	if (!(str = ft_strnew((size_t)length)))
		return (NULL);
	str[--length] = n_tmp % 10 + '0';
	while (n_tmp /= 10)
		str[--length] = n_tmp % 10 + '0';
	if (num < 0)
		str[0] = '-';
	return (str);
}
