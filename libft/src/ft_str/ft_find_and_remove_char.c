/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_and_remove_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:18:18 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:19:03 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_find_and_remove_char(char *str, char find)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == find)
		{
			j = i;
			while (str[j + 1])
			{
				str[j] = str[j + 1];
				j++;
			}
			str[j] = '\0';
			break ;
		}
		i++;
	}
	new_str = ft_strdup(str);
	return (new_str);
}
