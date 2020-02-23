#include "../includes/lem_in.h"

t_room		*bfs_check_path(t_lem *lem, t_room *start, char *end)
{
	t_ht	*seen;
	t_queue	*queue;
	t_qnode *current;
	t_room *starting_path;
	t_room *head_path;
	int i;

	seen = create_seen();
	queue = queue_create();
	i = 0;
	enqueue(queue, start);
	start->bfs_lvl = 0;
	starting_path = NULL;
	head_path = start;
	while (queue->front)
	{
		current = dequeue(queue);
		if (current == NULL || current->room == NULL)
			continue;
		if (!current->room->name)
			continue;
		if (!ht_get(seen, current->room->name))
		{
			add_next_path(&current->room, &starting_path, &head_path);
			ht_set(seen, current->room->name, &current->room);
			if (ft_strequ(current->room->name, end))
			{
				free(current);
				free(queue);
				free_seen(&seen);
				return (head_path);
			}
			while (i < current->room->out_degree)
			{
				set_reload_bfs_lvl(lem, current, i, end);
				if (!ht_get(seen, current->room->out_links[i])) // если его нет в просмотренном добавляем в очередь
					enqueue(queue, ht_get(lem->ht, current->room->out_links[i]));
//				print_queue(queue);
//				print_ht_seen(seen);
				i++;
			}
		}
		free(current);
		i = 0;
	}
	free(queue);
	free_seen(&seen);
	return (NULL);
}

void add_next_path(t_room **next, t_room **starting_path, t_room **head)
{
	if ((*starting_path) == NULL)
	{
		(*starting_path) = *next;
		(*head) = *starting_path;
		(*starting_path)->next = NULL;
	}
	else
	{
		(*starting_path)->next = *next;
		(*starting_path) = (*starting_path)->next;
		(*starting_path)->next = NULL;
	}
}

void set_reload_bfs_lvl(t_lem *lem, t_qnode *current, int	i, char *end)
{
	t_room *curr_room;

	curr_room = ht_get(lem->ht, current->room->out_links[i]);
	if (curr_room == NULL)
		return;
	curr_room->bfs_lvl = -1;
	if (ft_strequ(curr_room->name, end))
		curr_room->bfs_lvl = MAX_INTEGER;
	if (curr_room->bfs_lvl == -1 && !ft_strequ(current->room->name, end))
		curr_room->bfs_lvl = current->room->bfs_lvl + 1;
}