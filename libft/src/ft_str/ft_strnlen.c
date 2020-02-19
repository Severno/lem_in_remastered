/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:10:39 by sapril            #+#    #+#             */
/*   Updated: 2019/09/14 17:13:36 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strnlen(char *s, size_t len)
{
	size_t count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] && count < len)
		count++;
	return (count);
}
