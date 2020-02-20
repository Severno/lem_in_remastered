/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:05:13 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 20:05:48 by sapril           ###   ########.fr       */
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
			else if (is_ant(lem, lines, split_str) > 0 && lem->ants == -1)
				parse_ants(lem, &lines, split_str) == 0 ? terminate(&lem, INCORRECT_ANTS) : 0;
			else if (is_end_or_start(lem, split_str, &lines))
				parse_end_or_start(lem, &lines, split_str);
			else if (is_room(lem, split_str, &lines))
				parse_rooms(lem, &lines, split_str);
			else if (ft_strchr(lines, '-') && split_str[1] == NULL && is_link(lem, split_str, &lines))
				parse_links(lem, &lines, split_str);
			else
				free_line_info(&split_str, &lines);
	}
	if (lem->ants <= -1)
		terminate(&lem, INCORRECT_ANTS);
	return (1);
}

int parse_ants(t_lem *lem, char **lines, char **split_str)
{
	if (check_ants_num(*lines))
	{
		if ((lem->ants = ft_atoi(split_str[0])) < 0)
			terminate(&lem, INCORRECT_ANTS);
		free_line_info(&split_str, lines);
		return (1);
	}
	return (0);
}

int parse_end_or_start(t_lem *lem, char **lines, char **split_str)
{
	int		ret;
	char *tmp_end_start;
	t_room	*new_room;

	tmp_end_start = ft_strdup(split_str[0]);
	free_line_info(&split_str, lines);
	ret = get_next_line(lem->fd, lines);
	split_str = ft_strsplit(*lines, ' ');
	if (ret < 0 || !is_room(lem, split_str, lines))
	{
		free(tmp_end_start);
		free_line_info(&split_str, lines);
		terminate(&lem, INCORRECT_END);
	}
	if (!ht_get(lem->ht, split_str[0]))
	{
		if (ft_strequ(tmp_end_start, "##start"))
			lem->start = ft_strdup(split_str[0]);
		if (ft_strequ(tmp_end_start, "##end"))
			lem->end = ft_strdup(split_str[0]);
	}
	else
	{
		free(tmp_end_start);
		free_line_info(&split_str, lines);
		terminate(&lem, DUPLICATE_ROOM);
	}
	new_room = create_room(&split_str[0], ft_atoi(split_str[1]), ft_atoi(split_str[2]));
	ht_set(lem->ht, split_str[0], &new_room);
	lem->rooms_cap++;
	free_line_info(&split_str, lines);
	free(tmp_end_start);
	return (1);
}

int parse_rooms(t_lem *lem, char **lines, char **split_str)
{
	t_room	*new_room;

	new_room = create_room(&split_str[0], ft_atoi(split_str[1]), ft_atoi(split_str[2]));
	ht_set(lem->ht, split_str[0], &new_room);
	lem->rooms_cap++;
	free_line_info(&split_str, lines);
	return (1);
}

void add_link(t_room *room, char *link)
{
	room->links[room->links_degree] = ft_strcpy(room->links[room->links_degree], link);
	room->links_degree++;
}

int parse_links(t_lem *lem, char **lines, char **split_str)
{
	char *link_str;
	char *link1_str;
	char *link2_str;
	t_room	*link1;
	t_room	*link2;
	int biggest_delimeter;

	(void)lines;
	link_str = split_str[0];
	biggest_delimeter = get_biggest_delimeter(lem, link_str, ft_strlen(link_str));
	link1_str = lem_strdub(link_str, get_biggest_delimeter(lem, link_str, ft_strlen(link_str)));
	link2_str = lem_strdub(link_str + biggest_delimeter + 1,  ft_strlen(link_str));
	link1 = ht_get(lem->ht, link1_str);
	link2 = ht_get(lem->ht, link2_str);
	add_link(link1, link2_str);
	add_link(link2, link1_str);
	free(link1_str);
	free(link2_str);
	return (1);
}