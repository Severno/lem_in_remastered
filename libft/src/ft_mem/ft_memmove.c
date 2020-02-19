/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:35:19 by sapril            #+#    #+#             */
/*   Updated: 2019/10/23 13:21:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	char		*src_tmp;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	i = -1;
	if (src_tmp < dst_tmp)
		while (len--)
			*(dst_tmp + len) = *(src_tmp + len);
	else
		while (++i < len)
			*(dst_tmp + i) = *(src_tmp + i);
	return (dst);
}
