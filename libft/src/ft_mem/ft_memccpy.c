/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:47:40 by sapril            #+#    #+#             */
/*   Updated: 2019/09/17 12:35:21 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	i = 0;
	ch = (unsigned char)c;
	src_tmp = (unsigned char*)src;
	dst_tmp = (unsigned char*)dst;
	while (n-- > 0)
	{
		if (src_tmp[i] == ch)
		{
			dst_tmp[i++] = ch;
			return (dst_tmp + i);
		}
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (NULL);
}
