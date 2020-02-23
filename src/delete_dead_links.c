#include "../includes/lem_in.h"

void delete_current_link(t_room *from, t_room *to, int out_pos, int in_pos)
{
	ft_strclr(from->links[out_pos]);
	from->links[out_pos] = NULL;
	ft_strclr(to->links[in_pos]);
	to->links[in_pos] = NULL;
}

void	delete_useless_links(t_lem *lem, t_room *start)
{
	t_ht	*seen;
	t_queue	*queue;
	t_qnode *current;
	int i;
	int out_pos;

	seen = create_seen();
	queue = queue_create();
	i = 0;
	out_pos = 0;
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
			while (i < current->room->links_degree)
			{
				if (current->room->links[i])
				{
					if (current->room->bfs_lvl == ht_get(lem->ht, current->room->links[i])->bfs_lvl) // удаляет элементы которые ссылаются на один и тот же BFS уровень
					{
						out_pos = get_pos_link_in(
								ht_get(lem->ht, current->room->links[i])->links,
								current->room->name,
								ht_get(lem->ht, current->room->links[i])->links_degree);
						delete_current_link(current->room, ht_get(lem->ht, current->room->links[i]), i, out_pos);
					}
					if (!ht_get(seen, current->room->links[i])) // если его нет в просмотренном добавляем в очередь
						enqueue(queue, ht_get(lem->ht, current->room->links[i]));
				}
				i++;
			}
		}
		free(current);
		i = 0;
	}
	free(queue);
	free_seen(&seen);
}

void remove_dead_link(t_lem *lem, t_room *dead_room)
{
	t_room	*out_link;
	int		in_degr;
	int		pos_out_link;

	in_degr = 0;
	while (in_degr < dead_room->in_degree)
	{
		if (dead_room->in_links[in_degr])
		{
			out_link = ht_get(lem->ht, dead_room->in_links[in_degr]);
			pos_out_link = get_pos_link_out(out_link->out_links, dead_room->name, out_link->out_degree);
			free(out_link->out_links[pos_out_link]);
			out_link->out_links[pos_out_link] = NULL;
			free(dead_room->in_links[in_degr]);
			dead_room->in_links[in_degr] = NULL;
		}
		in_degr++;
	}
}
