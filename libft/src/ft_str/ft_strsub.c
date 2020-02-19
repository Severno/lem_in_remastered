/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:28:25 by sapril            #+#    #+#             */
/*   Updated: 2019/10/23 13:21:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	if (!s || (len + 1 == 0) || !(new_s = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (len-- > 0)
		new_s[i++] = *(s + start++);
	return (new_s);
}
