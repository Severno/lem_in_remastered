/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:57:55 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 10:59:02 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int get_pos_link_out(char **out_links, char *in_link, int out_degree)
{
	int i;

	i = 0;
	if (out_links && in_link)
	{
		while (i < out_degree)
		{
			if (out_links[i] != NULL && out_links[i][0] != '\0' &&ft_strequ(out_links[i], in_link))
				return (i);
			i++;
		}

	}
	return (-1);
}

void remove_dead_link(t_lem *lem, t_room *dead_room)
{
	t_room	*out_link;
	int		in_degr;
	int		pos_out_link;

	in_degr = 0;
	while (in_degr < dead_room->in_degree)
	{
		if (dead_room->in_link[in_degr])
		{
			out_link = ht_get(lem->ht, dead_room->in_link[in_degr]);
			pos_out_link = get_pos_link_out(out_link->out_link, dead_room->name, out_link->out_degree);
			free(out_link->out_link[pos_out_link]);
			out_link->out_link[pos_out_link] = NULL;
			free(dead_room->in_link[in_degr]);
			dead_room->in_link[in_degr] = NULL;
		}
		in_degr++;
	}
}

int get_pos_link_in(char **in_links, char *out_link, int in_degree)
{
	int i;

	i = 0;
	if (in_links && out_link)
	{
		while (i < in_degree)
		{
			if (in_links[i] != NULL && in_links[i][0] != '\0' && ft_strequ(in_links[i], out_link))
				return (i);
			i++;
		}
	}
	return (-1);
}

void delete_current_link(t_room *from, t_room *to, int out_pos, int in_pos)
{
	free(from->out_link[out_pos]);
	from->out_link[out_pos] = NULL;
	free(to->in_link[in_pos]);
	to->in_link[in_pos] = NULL;

}


void delete_cur_input_link(t_room *curr_room, t_lem *lem)
{
	int		real_out_links;
	int		curr_out_degree;
	t_room *deciding_room;
	int		out_delete_pos;
	int		in_delete_pos;

	real_out_links = get_real_out_links(curr_room);
	curr_out_degree = 0;
	if (real_out_links > 1 && !ft_strequ(curr_room->name, lem->start))
	{
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_link[curr_out_degree]);
			if (deciding_room == NULL)
			{
				curr_out_degree++;
				continue;
			}
			if ((get_real_in_links(deciding_room)) > 1)
			{
				out_delete_pos = get_pos_link_out(curr_room->out_link, deciding_room->name, curr_room->out_degree);
				in_delete_pos = get_pos_link_in(deciding_room->in_link, curr_room->name, deciding_room->in_degree);
				delete_current_link(curr_room, deciding_room, out_delete_pos, in_delete_pos);
			}
			curr_out_degree++;
		}
	}
}

void	delete_useless_links(t_lem *lem, t_room *start)
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
				if (ht_get(lem->ht, current->room->out_link[out_degree]) != NULL)
				{
					if (current->room->bfs_lvl == ht_get(lem->ht, current->room->out_link[out_degree])->bfs_lvl) // удаляет элементы которые ссылаются на один и тот же BFS уровень
					{
						delete_current_link(
								current->room,
								ht_get(lem->ht, current->room->out_link[out_degree]),
								out_degree,
								get_pos_link_in(
										ht_get(lem->ht, current->room->out_link[out_degree])->in_link,
										current->room->name,
										ht_get(lem->ht, current->room->out_link[out_degree])->in_degree
								)
						);
					}
//					delete_cur_input_link(current->room, ht_get(lem->ht, current->room->out_link[out_degree]), lem);
					if (!ht_get(seen, current->room->out_link[out_degree]))
						enqueue(queue, ht_get(lem->ht, current->room->out_link[out_degree]));
	//				print_queue(queue);
	//				print_ht_seen(seen);
//					if (current->room->out_link[out_degree])
//						ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->out_link[out_degree], ht_get(lem->ht, current->room->out_link[out_degree])->bfs_lvl);
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
//	ft_printf("Malloc entries %d\n", malloc_entries);
//	ft_printf("Freed entries %d\n", freed_entries);
}

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
			ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->name, current->room->bfs_lvl);
			while (out_degree < current->room->out_degree) // смотрим все исходящие ссылки из текущий комнаты
			{
				if (ht_get(lem->ht, current->room->out_link[out_degree]) != NULL)
				{
					delete_cur_input_link(current->room, lem);
					if (!ht_get(seen, current->room->out_link[out_degree]))
						enqueue(queue, ht_get(lem->ht, current->room->out_link[out_degree]));
					//				print_queue(queue);
					//				print_ht_seen(seen);
					if (current->room->out_link[out_degree])
						ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->out_link[out_degree], ht_get(lem->ht, current->room->out_link[out_degree])->bfs_lvl);
				}
				out_degree++;
			}
//			if (current->room->out_degree == 0 && current->room->bfs_lvl != MAX_INTEGER)
//				remove_dead_link(lem, current->room);
		}
//		print_queue(queue);
//		print_ht_seen(seen);
		free(current);
		out_degree = 0;
	}
	free(queue);
	free_seen(&seen);
//	ft_printf("Malloc entries %d\n", malloc_entries);
//	ft_printf("Freed entries %d\n", freed_entries);
}

void delete_cur_output_link(t_room *curr_room, t_lem *lem)
{
	int		real_out_links;
	int		curr_out_degree;
	t_room *deciding_room;
	int min_bfs_lvl;
	int		out_delete_pos;
	int		in_delete_pos;

	real_out_links = get_real_out_links(curr_room);
	curr_out_degree = 0;
	min_bfs_lvl = MAX_INTEGER;
	if (real_out_links > 1 && !ft_strequ(curr_room->name, lem->start))
	{
		reverse_bfs_set_lel(lem, ht_get(lem->ht, lem->end), curr_room->name);
		if (curr_room->out_link[curr_out_degree] != NULL && curr_room->out_link[curr_out_degree][0] != '\0')
			min_bfs_lvl = ht_get(lem->ht, curr_room->out_link[curr_out_degree])->bfs_lvl;
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_link[curr_out_degree]);
			if (curr_room->out_link[curr_out_degree] != NULL && curr_room->out_link[curr_out_degree][0] != '\0')
			{
				if ((deciding_room->bfs_lvl) < min_bfs_lvl)
					min_bfs_lvl = deciding_room->bfs_lvl;
			}
			curr_out_degree++;
		}
		curr_out_degree = 0;
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_link[curr_out_degree]);
			if (curr_room->out_link[curr_out_degree] != NULL && curr_room->out_link[curr_out_degree][0] != '\0')
			{
				if ((deciding_room->bfs_lvl) >= min_bfs_lvl && deciding_room->visited == 0)
				{
					out_delete_pos = get_pos_link_out(curr_room->out_link, deciding_room->name, curr_room->out_degree);
					in_delete_pos = get_pos_link_in(deciding_room->in_link, curr_room->name, deciding_room->in_degree);
					delete_current_link(curr_room, deciding_room, out_delete_pos, in_delete_pos);
					curr_out_degree++;
					continue;
				}
				if ((deciding_room->bfs_lvl) >= min_bfs_lvl && get_real_out_links(curr_room) >= 2 && deciding_room->visited == 1)
				{
					out_delete_pos = get_pos_link_out(curr_room->out_link, deciding_room->name, curr_room->out_degree);
					in_delete_pos = get_pos_link_in(deciding_room->in_link, curr_room->name, deciding_room->in_degree);
					delete_current_link(curr_room, deciding_room, out_delete_pos, in_delete_pos);
				}
			}
			curr_out_degree++;
		}
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
				if (ht_get(lem->ht, current->room->out_link[out_degree]) != NULL)
				{
					delete_cur_output_link(current->room,  lem);
					if (!ht_get(seen, current->room->out_link[out_degree]))
						enqueue(queue, ht_get(lem->ht, current->room->out_link[out_degree]));
					//				print_queue(queue);
					//				print_ht_seen(seen);
//					if (current->room->out_link[out_degree])
//						ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->out_link[out_degree], ht_get(lem->ht, current->room->out_link[out_degree])->bfs_lvl);
				}
				out_degree++;
			}
//			if (current->room->out_degree == 0 && current->room->bfs_lvl != MAX_INTEGER)
//				remove_dead_link(lem, current->room);
		}
//		print_queue(queue);
//		print_ht_seen(seen);
		free(current);
		out_degree = 0;
	}
	free(queue);
	free_seen(&seen);
//	ft_printf("Malloc entries %d\n", malloc_entries);
//	ft_printf("Freed entries %d\n", freed_entries);
}