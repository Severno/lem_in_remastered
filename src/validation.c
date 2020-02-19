/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:19:58 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 14:56:51 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int is_end_or_start(t_lem *lem, char **split_str, char **lines)
{
	if (ht_get(lem->ht, split_str[0]))
	{
		free_line_info(&split_str, lines);
		terminate(&lem, DUPLICATE_ROOM);
	}
	if (ft_strequ(split_str[0], "##end") && lem->end == NULL)
		return (2);
	else if (ft_strequ(split_str[0], "##start") && lem->start == NULL)
		return (1);
	return (0);
}

int is_room(t_lem *lem, char **split_str, char **lines)
{
	if (ht_get(lem->ht, split_str[0]))
	{
		free_line_info(&split_str, lines);
		terminate(&lem, DUPLICATE_ROOM);
	}
	if (split_str[0] && split_str[1] && split_str[2])
	{
		if (check_coord_valid(split_str[1], split_str[2]))
			return (1);
	}
	return (0);
}

int is_connection(t_lem *lem, char **split_connections)
{
	if (ht_get(lem->ht, split_connections[0]) && ht_get(lem->ht, split_connections[1]))
		return (1);
	return (0);
}

int is_ant(const char *lines, char **split_str)
{
	if (ft_strchr(lines, '-'))
		return (-1);
	if (ft_str_is_numeric_no_spaces(split_str[0]) && split_str[1] == NULL && !ft_strchr(lines, '-'))
		return (1);
	return (0);
}

int is_comment(const char *lines)
{
	if (lines[0] == '#' && lines[1] != '#')
		return (1);
	return (0);
}