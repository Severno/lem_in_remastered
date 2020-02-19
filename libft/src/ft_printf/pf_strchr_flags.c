/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strchr_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:53:57 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:53:57 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		pf_strchr_flags(const char *s, int c, int *iter)
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
	*iter += 1;
	return (*(ts + i));
}
