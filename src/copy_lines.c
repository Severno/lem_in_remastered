/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:11:46 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 13:21:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*lem_strcat(char *s1, const char *s2, int *bytes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i++] = s2[j++];
		(*bytes)++;
	}
	s1[i] = '\0';
	(*bytes)++;
	return (s1);
}

char	*concat_lines(char *dst, char *src, int *bytes, int *mult)
{
	char *tmp;
	if ((*bytes) + 100 >= LINE_SIZE)
	{
		*mult += 1;
		tmp = ft_strnew(LINE_SIZE * (*mult));
		ft_strcpy(tmp, dst);
		free(dst);
		tmp = lem_strcat(tmp, src, bytes);
		tmp = lem_strcat(tmp, "\n", bytes);
		return (tmp);
	}
	dst = lem_strcat(dst, src, bytes);
	dst = lem_strcat(dst, "\n", bytes);
	return (dst);
}