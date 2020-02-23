#include "../includes/lem_in.h"

void	delete_input_links(t_lem *lem, t_room *start)
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
//		print_queue(queue);
//		print_ht_seen(seen);
		current = dequeue(queue);
		if (!current || !current->room)
			continue;
//		print_queue(queue);
//		print_ht_seen(seen);
//		ft_printf(BLUE"Current working %s \n"RESET, current->room->name);
		if (!ht_get(seen, current->room->name)) // проверяем есть ли в просмотренных
		{
			ht_set(seen, current->room->name, &current->room); // если нет, добавляем в просмотренные
//			ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->name, current->room->bfs_lvl);
			while (out_degree < current->room->out_degree) // смотрим все исходящие ссылки из текущий комнаты
			{
				if (ht_get(lem->ht, current->room->out_links[out_degree]) != NULL)
				{
					delete_cur_input_link(current->room, lem);
					if (!ht_get(seen, current->room->out_links[out_degree]))
						enqueue(queue, ht_get(lem->ht, current->room->out_links[out_degree]));
					//				print_queue(queue);
					//				print_ht_seen(seen);
//					if (current->room->out_links[out_degree])
//						ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->out_links[out_degree], ht_get(lem->ht, current->room->out_links[out_degree])->bfs_lvl);
				}
				out_degree++;
			}
			if (current->room->out_degree == 0 && current->room->bfs_lvl != MAX_INTEGER)
				remove_dead_link(lem, current->room);
		}
//		print_queue(queue);
//		print_ht_seen(seen);
		free(current);
		out_degree = 0;
	}
	free(queue);
	free_seen(&seen);
}

void delete_cur_input_link(t_room *curr_room, t_lem *lem)
{
	int		real_out_links;
	int		real_in_links;
	int		curr_out_degree;
	t_room *deciding_room;
	int		out_delete_pos;
	int		in_delete_pos;

	real_out_links = get_real_out_links(lem, curr_room);
	curr_out_degree = 0;
	real_in_links = -1;
	if (real_out_links > 1 && !ft_strequ(curr_room->name, lem->start))
	{
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_links[curr_out_degree]);
			if (deciding_room == NULL)
			{
				real_in_links = (get_real_in_links(lem, deciding_room));
				curr_out_degree++;
				continue;
			}
			if (real_in_links > 1)
			{
				out_delete_pos = get_pos_link_out(curr_room->out_links, deciding_room->name, curr_room->out_degree);
				in_delete_pos = get_pos_link_in(deciding_room->in_links, curr_room->name, deciding_room->in_degree);
				delete_current_link_out_in(curr_room, deciding_room, out_delete_pos, in_delete_pos);
			}
			curr_out_degree++;
		}
	}
}

void delete_current_link_out_in(t_room *from, t_room *to, int out_pos, int in_pos)
{
	ft_strclr(from->out_links[out_pos]);
//	free(from->out_links[out_pos]);
	from->out_links[out_pos] = NULL;
	ft_strclr(to->in_links[in_pos]);
//	free(to->in_links[in_pos]);
	to->in_links[in_pos] = NULL;
}