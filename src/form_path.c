/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:45:59 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 21:46:15 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int next_path(t_lem *lem, t_room *curr_room, t_room *start_path_room)
{
	int out_degr_cur;
	int is_valid_path;
	int is_finished;
	t_room *working_room;
	(void)start_path_room;

	out_degr_cur = 0;
	is_valid_path = 0;
	is_finished = 0;
	if (ft_strequ(curr_room->name, lem->end))
	{
		curr_room->next = NULL;
		is_finished = 1;
		return (1);
	}
	while (out_degr_cur < curr_room->out_degree)
	{
		working_room = ht_get(lem->ht, curr_room->out_links[out_degr_cur]);
		if (!working_room)
		{
			out_degr_cur++;
			continue;
		}
		curr_room->next = working_room;
		is_valid_path = next_path(lem, curr_room->next, NULL);
		if (is_valid_path == -1)
			return (-1);
		else if (is_valid_path == 1)
			return (1);
		out_degr_cur++;
	}
	if (!ft_strequ(curr_room->name, lem->end))
		return (-1);
	return (is_valid_path);
}

void form_paths(t_lem *lem, t_room *start)
{
	int out_degr_cur;
	int is_valid_path;
	int path_count;
	t_room *cur_room;

	out_degr_cur = 0;
//	out_degr_work= 0;
	path_count = 1;
	is_valid_path = 0;
	ft_printf(RED"Start\n"RESET);
	while (out_degr_cur < start->out_degree)
	{
		cur_room = ht_get(lem->ht, start->out_links[out_degr_cur]);
		if (!cur_room)
		{
			out_degr_cur++;
			continue;
		}
		is_valid_path = next_path(lem, cur_room, NULL);
		if (is_valid_path == -1)
		{
			free(start->out_links[out_degr_cur]);
			start->out_links[out_degr_cur] = NULL;
		}
		ft_putchar('\n');
//		out_degr_work = 0;
		out_degr_cur++;
		path_count++;
	}
}