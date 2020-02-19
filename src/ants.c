/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:49:16 by sapril            #+#    #+#             */
/*   Updated: 2020/02/17 15:15:13 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void run_current_lvl(t_ht *ants_and_rooms, int curr_ant, t_lem *lem)
{
	int tmp_ants;
	char *curr_ant_key;
	t_room *curr_ant_room;

	tmp_ants = 1;
	print_current_ants_position(ants_and_rooms, curr_ant, lem);
	while (tmp_ants < curr_ant)
	{
		curr_ant_key = ft_itoa(tmp_ants);
		curr_ant_room = ht_get(ants_and_rooms, curr_ant_key);
		if (curr_ant_room && curr_ant_room->next)
			ht_set(ants_and_rooms, curr_ant_key, &curr_ant_room->next);
		if (curr_ant_room == ht_get(lem->ht, lem->end))
		{
			ants_and_rooms->entries[hash(curr_ant_key)] = NULL;
			lem->ants_finished++;
		}
		tmp_ants++;
	}
}

void launch_ants(t_lem *lem, t_room *start, int ants)
{
	t_ht	*ants_and_rooms;
	t_room	*curr_room;
	int		out_degr_cur;
	int		curr_ant;

	curr_ant = 1;
	out_degr_cur = 0;
	ants_and_rooms = ht_create();
	while (lem->ants_finished < ants)
	{
		while (out_degr_cur < start->out_degree)
		{
			curr_room = ht_get(lem->ht, start->out_link[out_degr_cur]);
			if (curr_ant <= ants && curr_room && curr_room->name != NULL && curr_room->name[0] != '\0')
				ht_set(ants_and_rooms, ft_itoa(curr_ant++), &curr_room);
			out_degr_cur++;
		}
		run_current_lvl(ants_and_rooms, curr_ant, lem);
		out_degr_cur = 0;
	}
	print_current_ants_position(ants_and_rooms, curr_ant, lem);
}