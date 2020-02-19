/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_start_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:02:05 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:49:59 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_check_start_spaces(const char *s, size_t size)
{
	size_t	i;

	if (!s)
		return (0);
	if (size == 0)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return (0);
	return (i);
}
