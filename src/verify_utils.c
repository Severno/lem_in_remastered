/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:00:02 by sapril            #+#    #+#             */
/*   Updated: 2020/02/27 17:00:02 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** My room name must not contains other characters than a to z,
** A to Z, 0 to 9 and the character _
** Room coordinates must be positive integers, inferior to the INT_MAX
*/

void	verify_rooms_format(char **splited_s, char *line, t_parse *parser)
{
	int		x;
	int		y;

	x = 0;
	while (splited_s[0][x])
	{
		if (!ft_isalnum(splited_s[0][x]) && splited_s[0][x] != '_'
			&& splited_s[0][x] != '|' && splited_s[0][x] != '\'')
			syntax_error(line, MSG_ROOM_FORMAT, parser->nbr_line);
		x++;
	}
	y = 1;
	while (y <= 2)
	{
		x = 0;
		while (splited_s[y][x])
			if (!ft_isdigit(splited_s[y][x++]))
				syntax_error(line, MSG_ROOM_CONT_UINT, parser->nbr_line);
		if (ft_atoll(splited_s[y]) > 2147483647 ||
				ft_strlen(splited_s[y]) > 12)
			syntax_error(line, MSG_COOR_SUPP_INT, parser->nbr_line);
		y++;
	}
}

int		rooms_contains_name(char *name, t_parse *parser)
{
	t_room_parse	*tmp;

	tmp = parser->room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		rooms_contains_coor(int x, int y, t_parse *parser)
{
	t_room_parse	*tmp;

	tmp = parser->room;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
