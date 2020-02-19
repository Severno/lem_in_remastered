/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:38:07 by sapril            #+#    #+#             */
/*   Updated: 2019/09/18 15:20:55 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_s)
	{
		ft_strcpy(new_s, s1);
		ft_strcat(new_s, s2);
	}
	else
		return (NULL);
	return (new_s);
}
