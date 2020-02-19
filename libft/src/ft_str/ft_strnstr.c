/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:34:13 by sapril            #+#    #+#             */
/*   Updated: 2019/09/17 12:35:21 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ts1;
	char	*ts2;

	if (!*needle)
		return ((char *)haystack);
	ts1 = (char*)haystack;
	ts2 = (char*)needle;
	i = 0;
	j = 0;
	while (ts1[i] && i < len)
	{
		if (ts1[i] == ts2[j])
		{
			while (ts2[j] && ts1[j + i] == ts2[j] && (j + i) < len)
				j++;
			if (!ts2[j])
				return (&ts1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
