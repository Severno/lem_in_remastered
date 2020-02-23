/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:45:59 by sapril            #+#    #+#             */
/*   Updated: 2020/02/23 18:09:03 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room **form_paths(t_lem *lem, t_room *start)
{
	int out_degr_cur;
	int path_count;
	int i;
	t_room **path_arr;
	t_room *cur_room;

	out_degr_cur = 0;
	path_count = 1;
	i = 0;
	path_arr = ft_memalloc(sizeof(t_room *) * start->out_degree);
	while (i < start->out_degree)
		path_arr[i++] = ft_memalloc(sizeof(t_room));
	while (out_degr_cur < start->out_degree)
	{
		cur_room = ht_get(lem->ht, start->out_links[out_degr_cur]);
		if (!cur_room)
		{
			out_degr_cur++;
			continue;
		}
		path_arr[out_degr_cur] = bfs_check_path(lem, cur_room, lem->end);
		if (path_arr[out_degr_cur] == NULL)
		{
			free(start->out_links[out_degr_cur]);
			start->out_links[out_degr_cur] = NULL;
		}
		out_degr_cur++;
		path_count++;
	}
	return (path_arr);
}