#include "../includes/lem_in.h"

void find_shortest_way(t_lem *lem, t_room *current)
{
	int out_degr_cur;
	int path_count;
	int i;
	int min_bfs;
	int real_out_links;
	t_room **path_arr;
	t_room *cur_room;

	out_degr_cur = 0;
	path_count = 1;
	i = 0;
	min_bfs = MAX_INTEGER;
	path_arr = ft_memalloc(sizeof(t_room *) * current->out_degree);
	while (i < current->out_degree)
		path_arr[i++] = ft_memalloc(sizeof(t_room));
	while (out_degr_cur < current->out_degree)
	{
		cur_room = ht_get(lem->ht, current->out_links[out_degr_cur]);
		if (!cur_room)
		{
			out_degr_cur++;
			continue;
		}
		path_arr[out_degr_cur] = bfs_check_path(lem, cur_room, lem->end);
		if (path_arr[out_degr_cur] == NULL)
		{
			free(current->out_links[out_degr_cur]);
			current->out_links[out_degr_cur] = NULL;
		}
		out_degr_cur++;
		path_count++;
	}
	out_degr_cur = 0;
	while (out_degr_cur < current->out_degree)
	{
		cur_room = path_arr[out_degr_cur];
		if (!cur_room)
		{
			out_degr_cur++;
			continue;
		}
		if (cur_room->name == NULL && cur_room->out_links == NULL)
		{
			out_degr_cur++;
			continue;
		}
		while (cur_room->next && cur_room->next->next)
			cur_room = cur_room->next;
		if (min_bfs > cur_room->bfs_lvl)
			min_bfs = cur_room->bfs_lvl;
		out_degr_cur++;
	}
	out_degr_cur = 0;
	while (out_degr_cur < current->out_degree)
	{
		cur_room = path_arr[out_degr_cur];
		if (!cur_room)
		{
			out_degr_cur++;
			continue;
		}
		while (cur_room->next && cur_room->next->next)
			cur_room = cur_room->next;
		real_out_links = get_real_out_links(lem, current);
		if (cur_room->bfs_lvl >= min_bfs && real_out_links >= 2 && !ft_strequ(cur_room->name, lem->end))
		{
			free(current->out_links[out_degr_cur]);
			current->out_links[out_degr_cur] = NULL;
		}
		out_degr_cur++;
	}
}

void	delete_output_links(t_lem *lem, t_room *start)
{
	t_ht	*seen;
	t_queue	*queue;
	t_qnode *current;
	int		out_degree;

	out_degree = 0;
	seen = create_seen();
	queue = queue_create();
	enqueue(queue, start);
	start->bfs_lvl = 0;
	while (queue->front)
	{
		current = dequeue(queue);
		if (current == NULL || current->room == NULL)
			continue;
		if (!current->room->name)
			continue;
		if (!ht_get(seen, current->room->name))
		{
			ht_set(seen, current->room->name, &current->room);
			while (out_degree < current->room->out_degree)
			{
				if (ht_get(lem->ht, current->room->out_links[out_degree]) != NULL)
				{
					if (get_real_out_links(lem, current->room) >= 2 && !ft_strequ(lem->start, current->room->name))
					{
						find_shortest_way(lem, current->room);
						out_degree = 0;
						continue;
					}
					if (!ht_get(seen, current->room->out_links[out_degree]))
						enqueue(queue, ht_get(lem->ht, current->room->out_links[out_degree]));
				}
				out_degree++;
			}
		}
		free(current);
		out_degree = 0;
	}
	free(queue);
	free_seen(&seen);
}