/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:31:38 by sapril            #+#    #+#             */
/*   Updated: 2020/02/21 15:03:44 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int malloc_entries = 0;
int freed_entries = 0;

t_ht		*create_seen()
{
	t_ht *new_ht;
	int i;

	if (!(new_ht = ft_memalloc(sizeof(t_ht))))
		return (NULL);
	if (!(new_ht->entries = ft_memalloc(sizeof(t_entry *) * (TABLE_SIZE))))
		return (NULL);
	i = 0;
	while (i < TABLE_SIZE)
	{
		new_ht->entries[i++] = ft_memalloc(sizeof(t_entry));
		malloc_entries++;
	}
	return (new_ht);
}

void set_bfs_lvl(t_lem *lem, t_qnode *current, int	i, char *end)
{
	t_room *curr_room;

	curr_room = ht_get(lem->ht, current->room->links[i]);
	if (curr_room == NULL)
		return;
	if (ft_strequ(curr_room->name, end))
		curr_room->bfs_lvl = MAX_INTEGER;
	if (curr_room->bfs_lvl == -1 && !ft_strequ(current->room->name, end))
		curr_room->bfs_lvl = current->room->bfs_lvl + 1;
}

void		bfs_set_lvl(t_lem *lem, t_room *start, char *end)
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
//		print_queue(queue);
//		print_ht_seen(seen);
//		ft_printf(BLUE"Current working %s \n"RESET, current->room->name);
//		ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->name, current->room->bfs_lvl);
		if (!ht_get(seen, current->room->name))
		{
			ht_set(seen, current->room->name, &current->room);
			while (i < current->room->links_degree)
			{
				set_bfs_lvl(lem, current, i, end);
				if (!ht_get(seen, current->room->links[i])) // если его нет в просмотренном добавляем в очередь
					enqueue(queue, ht_get(lem->ht, current->room->links[i]));
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
}

