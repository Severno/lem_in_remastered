/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:59:32 by sapril            #+#    #+#             */
/*   Updated: 2020/02/27 16:59:32 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_next_room(t_engine *engine, int i_room)
{
	int		i;
	int		minimal;
	int		dist_min;

	i = 0;
	dist_min = -1;
	while (i < engine->rooms[i_room].nb_paths)
	{
		if (engine->rooms[engine->rooms[i_room].paths[i]].blocked == 0 &&
			engine->rooms[engine->rooms[i_room].paths[i]].dist != -1)
		{
			if (dist_min == -1 ||
				(engine->rooms[engine->rooms[i_room].paths[i]].dist < dist_min
				&& engine->rooms[i_room].dist >
					engine->rooms[engine->rooms[i_room].paths[i]].dist))
			{
				dist_min = engine->rooms[engine->rooms[i_room].paths[i]].dist;
				minimal = engine->rooms[i_room].paths[i];
			}
		}
		i++;
	}
	return (minimal);
}

int		used_room(t_engine *engine, int i_room)
{
	int		i;
	int		j;

	i = 0;
	while (i < engine->nb_paths)
	{
		j = 1;
		while (engine->paths[i][j] != 1)
		{
			if (engine->paths[i][j] == i_room)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
