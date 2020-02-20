/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:05:00 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 21:49:44 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_lines(char *lines)
{
	size_t i;

	i = 0;
	while (lines[i])
		ft_putchar(lines[i++]);
}

void print_ht_seen(t_ht *seen)
{
	int i;

	i = 0;

	ft_printf("Already seen ");
	while (i < TABLE_SIZE)
	{
		if (seen->entries[i]->value)
			ft_printf("%s ", seen->entries[i]->value->name);
		i++;
	}
	ft_putchar('\n');
}

void print_rooms(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < TABLE_SIZE)
	{
		if (lem->ht->entries[i])
		{
			ft_printf(RED"----Root NAME = %s, X = %d, Y = %d ----\n"RESET, lem->ht->entries[i]->value->name,
					lem->ht->entries[i]->value->coord_x, lem->ht->entries[i]->value->coord_y);
			while (j < lem->ht->entries[i]->value->links_degree)
			{
				if (lem->ht->entries[i]->value->links[j])
					ft_printf(BLUE"Link = %s\n"RESET, ht_get(lem->ht, lem->ht->entries[i]->value->links[j])->name);
				j++;
			}
			ft_putchar('\n');
		}
		j = 0;
		i++;
	}
}

void print_rooms_out_in(t_lem *lem)
{
	int in_degree;
	int out_degree;
	int rooms;
	int i;

	rooms = 49;
	in_degree = 0;
	out_degree = 0;
	i = 0;
	while (i < TABLE_SIZE)
	{
		if (lem->ht->entries[i])
		{
			ft_printf(RED"----Root NAME = %s, X = %d, Y = %d ----\n"RESET, lem->ht->entries[i]->value->name, lem->ht->entries[i]->value->coord_x, lem->ht->entries[i]->value->coord_y);
			while (out_degree < lem->ht->entries[i]->value->out_degree)
			{
				ft_printf(BLUE"Out link = %s\n"RESET, lem->ht->entries[i]->value->out_links[out_degree]);
				out_degree++;
			}
			while (in_degree < lem->ht->entries[i]->value->in_degree)
			{
				ft_printf(BLUE"In link = %s\n"RESET, lem->ht->entries[i]->value->in_links[in_degree]);
				in_degree++;
			}
			in_degree = 0;
			out_degree = 0;
			rooms++;
			ft_putchar('\n');
		}
		i++;
	}
}

void print_out_rooms(t_room *room)
{
	int i;

	i = 0;
	while (i < room->out_degree)
	{
		if (room->out_links[i] == NULL || room->out_links[i][0] == '\0')
		{
			i++;
			continue;
		}
		ft_printf("i = %d, link = %s\n", i, room->out_links[i]);
		i++;
	}
}

void print_paths_linked_list(t_lem *lem, t_room *start)
{
	int out_degr_cur;
	int path_count;
	t_room *cur_room;

	out_degr_cur = 0;
	path_count = 1;
	ft_printf(RED"Start\n"RESET);
	print_out_rooms(start);
	while (out_degr_cur < start->out_degree)
	{

		cur_room = ht_get(lem->ht, start->out_links[out_degr_cur]);
		ft_printf("Path %d. %s", path_count, start->name);
		if (!cur_room)
		{
			ft_putchar('\n');
			out_degr_cur++;
			continue;
		}
		while (cur_room)
		{
			ft_printf(" -> %s", cur_room->name);
			cur_room = cur_room->next;
		}
		ft_putchar('\n');
		out_degr_cur++;
		path_count++;
	}
}

void print_current_ants_position(t_ht *ants_and_rooms, int curr_ant, t_lem *lem)
{
	char *tmp_itoa;
	int tmp_ants;
	t_room *curr_room;
	(void)lem;

	tmp_ants = 1;
	while (tmp_ants < curr_ant)
	{
		tmp_itoa = ft_itoa(tmp_ants);
		curr_room = ht_get(ants_and_rooms, tmp_itoa);
		if (!curr_room)
		{
			tmp_ants++;
			free(tmp_itoa);
			continue;
		}
		ft_printf("L%d-%s ", tmp_ants, curr_room->name);
		free(tmp_itoa);
		tmp_ants++;
	}
	ft_putchar('\n');
}