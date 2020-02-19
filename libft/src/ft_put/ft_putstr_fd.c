/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:48:06 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 08:45:48 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	if (s)
	{
		ret = 0;
		while (s[i] && (ret = ft_putchar_fd(s[i++], fd)))
			;
	}
}
