/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:13:14 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 22:22:10 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void delete_current_link(t_room *from, t_room *to, int out_pos, int in_pos)
{
	ft_strclr(from->links[out_pos]);
//	free(from->links[out_pos]);
	from->links[out_pos] = NULL;
	ft_strclr(to->links[in_pos]);
//	free(to->links[in_pos]);
	to->links[in_pos] = NULL;
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
//		print_queue(queue);
//		print_ht_seen(seen);
//		ft_printf(BLUE"Current working %s \n"RESET, current->room->name);
//		ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->name, current->room->bfs_lvl);
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

void add_out_in_link(t_room *out, t_room *in, char *out_str, char *in_str)
{
	out->out_links[out->out_degree] = ft_strcpy(out->out_links[out->out_degree], in_str);
	in->in_links[in->in_degree] = ft_strcpy(in->in_links[in->in_degree], out_str);
	in->in_degree++;
	out->out_degree++;
}

int get_pos_link_out(char **out_links, char *in_link, int out_degree)
{
	int i;

	i = 0;
	if (out_links && in_link)
	{
		while (i < out_degree)
		{
			if (out_links[i] != NULL && out_links[i][0] != '\0' && ft_strequ(out_links[i], in_link))
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

void	align_links(t_lem *lem, t_room *start)
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
//		print_queue(queue);
//		print_ht_seen(seen);
//		ft_printf(BLUE"Current working %s \n"RESET, current->room->name);
//		ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->name, current->room->bfs_lvl);
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
					if (!ht_get(seen, current->room->links[i])) // если его нет в просмотренном добавляем в очередь
						enqueue(queue, ht_get(lem->ht, current->room->links[i]));
				}
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
	if (real_out_links > 1 && !ft_strequ(curr_room->name, lem->start))
	{
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_links[curr_out_degree]);
			real_in_links = (get_real_in_links(lem, curr_room));
			if (deciding_room == NULL)
			{
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

void reverse_set_bfs_lvl(t_lem *lem, t_qnode *current, int	in_degree, char *end)
{
	t_room *curr_room;

	curr_room = ht_get(lem->ht, current->room->in_links[in_degree]);
	if (curr_room == NULL)
		return;
	if (ft_strequ(curr_room->name, end))
		curr_room->bfs_lvl = MAX_INTEGER;
	else
		curr_room->bfs_lvl = current->room->bfs_lvl + 1;
}

void reverse_bfs_set_lel(t_lem *lem, t_room *start, char *end)
{
	t_ht	*seen;
	t_queue	*queue;
	t_qnode *current;
	int		in_degree;

	in_degree = 0;
	seen = create_seen();
	queue = queue_create();
	enqueue(queue, start);
	start->bfs_lvl = 0;
	while (queue->front)
	{
//		print_queue(queue);
//		print_ht_seen(seen);
		current = dequeue(queue);
		if (current == NULL || current->room == NULL)
			continue;
		if (!current->room->name)
			continue;
//		print_queue(queue);
//		print_ht_seen(seen);
//		ft_printf(BLUE"Current working %s \n"RESET, current->room->name);
		if (!ht_get(seen, current->room->name)) // проверяем есть ли в просмотренных
		{
			ht_set(seen, current->room->name, &current->room);
			current->room->visited = 1;// если нет, добавляем в просмотренные
//			ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->name, current->room->bfs_lvl);
			while (in_degree < current->room->in_degree) // смотрим все исходящие ссылки из текущий комнаты
			{
				reverse_set_bfs_lvl(lem, current, in_degree, end);
				if (!ht_get(seen, current->room->in_links[in_degree])) // если его нет в просмотренном добавляем в очередь
					enqueue(queue, ht_get(lem->ht, current->room->in_links[in_degree]));
//				print_queue(queue);
//				print_ht_seen(seen);
//				ft_printf("Current node = %s, bfs_lvl = %d\n", current->room->in_link[in_degree], ht_get(lem->ht, current->room->in_link[in_degree])->bfs_lvl);
				in_degree++;
			}
		}
//		print_queue(queue);
//		print_ht_seen(seen);
		free(current);
		in_degree = 0;
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

	real_out_links = get_real_out_links(lem, curr_room);
	curr_out_degree = 0;
	min_bfs_lvl = MAX_INTEGER;
//	print_rooms_out_in(lem);
	if (real_out_links > 1 && !ft_strequ(curr_room->name, lem->start))
	{
		reverse_bfs_set_lel(lem, ht_get(lem->ht, lem->end), curr_room->name);
		if (curr_room->out_links[curr_out_degree] != NULL && curr_room->out_links[curr_out_degree][0] != '\0')
			min_bfs_lvl = ht_get(lem->ht, curr_room->out_links[curr_out_degree])->bfs_lvl;
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_links[curr_out_degree]);
			if (curr_room->out_links[curr_out_degree] != NULL && curr_room->out_links[curr_out_degree][0] != '\0')
			{
				if ((deciding_room->bfs_lvl) < min_bfs_lvl)
					min_bfs_lvl = deciding_room->bfs_lvl;
			}
			curr_out_degree++;
		}
		curr_out_degree = 0;
		while (curr_out_degree < curr_room->out_degree)
		{
			deciding_room = ht_get(lem->ht, curr_room->out_links[curr_out_degree]);
			if (curr_room->out_links[curr_out_degree] != NULL && curr_room->out_links[curr_out_degree][0] != '\0')
			{
				real_out_links = get_real_out_links(lem, curr_room);
				if ((deciding_room->bfs_lvl) >= min_bfs_lvl && deciding_room->visited == 0)
				{
					out_delete_pos = get_pos_link_out(curr_room->out_links, deciding_room->name, curr_room->out_degree);
					in_delete_pos = get_pos_link_in(deciding_room->in_links, curr_room->name, deciding_room->in_degree);
					delete_current_link_out_in(curr_room, deciding_room, out_delete_pos, in_delete_pos);
					curr_out_degree++;
					continue;
				}
				if ((deciding_room->bfs_lvl) >= min_bfs_lvl && real_out_links >= 2 && deciding_room->visited == 1)
				{
					out_delete_pos = get_pos_link_out(curr_room->out_links, deciding_room->name, curr_room->out_degree);
					in_delete_pos = get_pos_link_in(deciding_room->in_links, curr_room->name, deciding_room->in_degree);
					delete_current_link_out_in(curr_room, deciding_room, out_delete_pos, in_delete_pos);
				}
			}
//			print_rooms_out_in(lem);
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
				if (ht_get(lem->ht, current->room->out_links[out_degree]) != NULL)
				{
					delete_cur_output_link(current->room,  lem);
					if (!ht_get(seen, current->room->out_links[out_degree]))
						enqueue(queue, ht_get(lem->ht, current->room->out_links[out_degree]));
				}
				out_degree++;
			}
		}
//		print_queue(queue);
//		print_ht_seen(seen);
		free(current);
		out_degree = 0;
	}
	free(queue);
	free_seen(&seen);
}