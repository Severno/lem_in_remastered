/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:59:27 by sapril            #+#    #+#             */
/*   Updated: 2020/02/27 16:59:27 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Depth First Search Algorithm
*/

static void		dfs(t_engine *engine, int index, int dist)
{
	int i;

	if (engine->rooms[index].blocked == 1)
		return ;
	if (engine->rooms[index].dist != -1 && dist > engine->rooms[index].dist)
		return ;
	engine->rooms[index].dist = dist;
	if (index == 0)
		return ;
	i = 0;
	while (i < engine->rooms[index].nb_paths)
	{
		dfs(engine, engine->rooms[index].paths[i], dist + 1);
		i++;
	}
}

/*
** Record the path like ROOM-ROOM-ROOM
** into an array of int
*/

static int		*record_path(t_engine *engine)
{
	int			*path;
	int			index;
	int			i;

	path = (int *)ft_memalloc(sizeof(int) * engine->nb_rooms + 1);
	index = 0;
	path[0] = engine->rooms[0].dist + 1;
	path[1] = 0;
	i = 2;
	while (index != 1)
	{
		path[i] = get_next_room(engine, index);
		index = path[i];
		i++;
	}
	return (path);
}

/*
** Reset the visited of room and block the path already taken
** We reset the START and END whatever the past paths
*/

static void		block_path(t_engine *engine)
{
	int		i_room;

	i_room = 2;
	engine->rooms[0].dist = -1;
	engine->rooms[1].dist = -1;
	while (i_room < engine->nb_rooms)
	{
		engine->rooms[i_room].dist = -1;
		if (used_room(engine, i_room))
			engine->rooms[i_room].blocked = 1;
		i_room++;
	}
}

/*
** After DFS, if the dist of start is -1, it means that
** it did not find any path
*/

void			start_engine(t_engine *engine)
{
	int		i;
	int		possible_paths_nb;

	possible_paths_nb = engine->rooms[0].nb_paths;
	possible_paths_nb = engine->rooms[1].nb_paths < possible_paths_nb ?
		engine->rooms[1].nb_paths : possible_paths_nb;
	engine->paths = (int **)ft_memalloc(sizeof(int *) * possible_paths_nb);
	i = 0;
	while (i < possible_paths_nb)
	{
		dfs(engine, 1, 0);
		if (engine->rooms[0].dist != -1)
		{
			engine->nb_paths += 1;
			engine->paths[i] = record_path(engine);
			block_path(engine);
		}
		i++;
	}
	if (engine->nb_paths == 0)
		general_error(MSG_NO_PATH);
	if (engine->debug)
		display_paths(engine);
	init_ants(engine);
}
