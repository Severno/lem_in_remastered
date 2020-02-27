/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:59:53 by sapril            #+#    #+#             */
/*   Updated: 2020/02/27 16:59:53 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	handle_comments(char **line, t_parse *parser)
{
	read_line(line, parser);
	while (is_comment(*line))
	{
		ft_strdel(line);
		read_line(line, parser);
	}
}

t_room	parse_room_from_chained_list(t_room_parse *old_room, t_parse *parser)
{
	t_room		new_room;

	new_room.nb_paths = 0;
	new_room.name = ft_strdup(old_room->name);
	ft_strdel(&old_room->name);
	new_room.start = old_room->start;
	new_room.end = old_room->end;
	new_room.dist = -1;
	new_room.blocked = 0;
	new_room.paths = (int *)ft_memalloc(sizeof(int) * parser->nb_rooms - 1);
	return (new_room);
}

int		parse_ants(char *str)
{
	int				i;
	intmax_t		ants;

	if (ft_strlen(str) == 0)
		syntax_error(str, MSG_NULL, 1);
	if (str[0] && str[0] == '-')
		syntax_error(str, MSG_ANTS_NEG, 1);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			syntax_error(str, MSG_FORMAT, 1);
	}
	if (ft_strlen(str) > 12)
		syntax_error(str, MSG_INT_MAX, 1);
	ants = ft_atoll(str);
	if (ants == 0)
		syntax_error(str, MSG_ZERO, 1);
	if (ants > 2147483647)
		syntax_error(str, MSG_INT_MAX, 1);
	return (ants);
}
