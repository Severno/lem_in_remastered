/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:38:38 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 11:17:34 by sapril           ###   ########.fr       */
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
		working_room = ht_get(lem->ht, curr_room->out_link[out_degr_cur]);
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
//
//	int out_degr;
//	int out_degr_in;
//	t_room *searching_room;
//
//	out_degr = 0;
//	out_degr_in = 0;
//	while (out_degr < curr_room->out_degree)
//	{
//		searching_room = ht_get(lem->ht, curr_room->out_link[out_degr]);
//		if (searching_room)
//		while (searching_room)
//		{
//			searching_room = searching_room->next;
//		}
//		out_degr++;
//	}
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
		cur_room = ht_get(lem->ht, start->out_link[out_degr_cur]);
		if (!cur_room)
		{
			out_degr_cur++;
			continue;
		}
		is_valid_path = next_path(lem, cur_room, NULL);
		if (is_valid_path == -1)
		{
			free(start->out_link[out_degr_cur]);
			start->out_link[out_degr_cur] = NULL;
		}
		ft_putchar('\n');
//		out_degr_work = 0;
		out_degr_cur++;
		path_count++;
	}
}

int is_path(t_lem *lem, t_room *start)
{
	int out_degr;
	int path_cap;
	t_room *curr_room;


	out_degr = 0;
	path_cap = 0;
	while (out_degr < start->out_degree)
	{
		curr_room = ht_get(lem->ht, start->out_link[out_degr]);
		if ((get_real_out_links(curr_room)) == 0)
		{
			out_degr++;
			continue;
		}
		while (curr_room)
		{
			if (ft_strequ(curr_room->name, lem->end))
				path_cap++;
			curr_room = curr_room->next;
		}
		out_degr++;
	}
	return path_cap;
}