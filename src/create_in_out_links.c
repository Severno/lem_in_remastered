#include "../includes/lem_in.h"

void add_out_in_link(t_room *out, t_room *in, char *out_str, char *in_str)
{
	out->out_links[out->out_degree] = ft_strcpy(out->out_links[out->out_degree], in_str);
	in->in_links[in->in_degree] = ft_strcpy(in->in_links[in->in_degree], out_str);
	in->in_degree++;
	out->out_degree++;
}

void	create_in_out_links(t_lem *lem, t_room *start)
{
	t_ht	*seen;
	t_queue	*queue;
	t_qnode *current;
	int i;

	seen = create_seen();
	queue = queue_create();
	i = 0;
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
					if (current->room->bfs_lvl < ht_get(lem->ht, current->room->links[i])->bfs_lvl)
					{
						add_out_in_link(current->room, ht_get(lem->ht, current->room->links[i]),
										current->room->name,
										ht_get(lem->ht, current->room->links[i])->name);
					}
					if (!ht_get(seen, current->room->links[i]))
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
