/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:05:13 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 15:26:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int parse(t_lem *lem)
{
	char	*lines;
	char	**split_str;

	while (get_next_line(lem->fd, &lines) > 0)
	{
		concat_lines(lem->concat->lines, lines, &lem->concat->bytes, &lem->concat->mult);
			split_str = ft_strsplit(lines, ' ');
			if (is_comment(lines))
			{
				free_line_info(&split_str, &lines);
				continue;
			}
			else if (is_ant(lines, split_str))
				parse_ants(lem, &lines, split_str) == 0 ? terminate(&lem, INCORRECT_ANTS) : 0;
			else if (is_end_or_start(lem, split_str, &lines))
				parse_end_or_start(lem, &lines, split_str);
			else if (is_room(lem, split_str, &lines))
				parse_rooms(lem, &lines, split_str);
			else if (ft_strchr(lines, '-'))
				add_link(lem, lines, split_str);
			else
				free_line_info(&split_str, &lines);
	}
}

int parse_ants(t_lem *lem, char **lines, char **split_str)
{
	if (check_ants_num(*lines))
	{
		lem->ants = ft_atoi(split_str[0]);
		free_line_info(&split_str, lines);
		return (1);
	}
	return (0);
}

int parse_end_or_start(t_lem *lem, char **lines, char **split_str)
{
	int		ret;
	t_room	*new_room;

	free_line_info(&split_str, lines);
	ret = get_next_line(lem->fd, lines);
	split_str = ft_strsplit(*lines, ' ');
	if (ret < 0 || !is_room(lem, split_str, lines))
	{
		free_line_info(&split_str, lines);
		terminate(&lem, INCORRECT_END);
	}
	if (!ht_get(lem->ht, split_str[0]))
	{
		if (ft_strequ(split_str[0], "##start"))
			lem->start = ft_strdup(split_str[0]);
		if (ft_strequ(split_str[0], "##end"))
			lem->end = ft_strdup(split_str[0]);
	}
	else
	{
		free_line_info(&split_str, lines);
		terminate(&lem, DUPLICATE_ROOM);
	}
	new_room = create_room(&split_str[0], ft_atoi(split_str[1]), ft_atoi(split_str[2]));
	ht_set(lem->ht, split_str[0], &new_room);
	lem->rooms_cap++;
	free_line_info(&split_str, lines);
}

int parse_rooms(t_lem *lem, char **lines, char **split_str)
{
	t_room	*new_room;

	new_room = create_room(&split_str[0], ft_atoi(split_str[1]), ft_atoi(split_str[2]));
	ht_set(lem->ht, split_str[0], &new_room);
	lem->rooms_cap++;
	free_line_info(&split_str, lines);
}

int parse_links()
{

}