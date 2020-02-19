/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:56:05 by sapril            #+#    #+#             */
/*   Updated: 2019/10/23 13:21:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*haystack_tmp;
	char	*needle_tmp;
	size_t	i;
	size_t	pos;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	haystack_tmp = (char *)haystack;
	needle_tmp = (char *)needle;
	while (haystack_tmp[i])
	{
		if (haystack_tmp[i] == needle_tmp[0])
		{
			pos = 1;
			while (haystack_tmp[pos + i] == needle_tmp[pos] && needle_tmp[pos])
				pos++;
			if (!needle_tmp[pos])
				return (&haystack_tmp[i]);
		}
		i++;
	}
	return (NULL);
}
