/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:53:05 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:53:13 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		pf_strchr(const char *s, int c)
{
	char	*ts;
	char	tc;
	size_t	i;

	ts = (char *)s;
	tc = c;
	i = 0;
	while (ts[i] != tc)
	{
		if (!ts[i])
			return (0);
		i++;
	}
	return (*(ts + i));
}
