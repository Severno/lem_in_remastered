/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:50:58 by sapril            #+#    #+#             */
/*   Updated: 2020/02/19 13:38:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// VALIDATION

//Map must have a valid number of ants: 1 <= number of ants <= INT_MAX.
//
//Map must have the start and the end rooms.
//
//Map must have no rooms with the same names. Each room name must be unique.
//
//Map must have no rooms with the same coordinates.
//
//Map must have one or more links.
//
//Each link must have valid names of the start and the end rooms. It means that rooms with these names are present in map file.
//
//Map must have no duplicates of links. There are no links that connect the same points.

int room_exist(t_lem *lem, char *str)
{
	if (ht_get(lem->ht, str))
		return (1);
	return (0);
}

void			add_link(t_lem *lem, char *lines, char **split_str)
{
	t_room 	*from;
	t_room	*to;
	char	*tmp;
	char	**split_connections;
	char	*check_room;

	free_split_str(&split_str);
	if (lines[0] == '-')
	{
		if ((check_room = ft_strchr(lines, '-')))
		{
//			ft_printf("Yes this is room %s\n", check_room); // TODO добавить проверку на ---8---, аргументы с дефисами.
			// можно сделать через ft_strcmp и выводить элемент где оин отличаются от тех что хранятся в lem->ht
		}
	}
	else
	{
		if ((check_room = ft_strchr(lines, '-')))
		{
//			ft_printf("Yes this is room %s\n", check_room + 1);
		}
	}

	split_connections = ft_strsplit(lines, '-');
	free(lines);
	lines = NULL;
	if (is_connection(lem, split_connections))
	{
		from = ht_get(lem->ht, split_connections[0]);
		to = ht_get(lem->ht, split_connections[1]);
		if (!from || !to)
		{
			printf("NO PATH\n");
			exit(free_data(&lem));
		}
		if (from->out_link[from->out_degree] == NULL)
		{
			from->out_link[from->out_degree] = ft_strnew(ft_strlen(to->name) + 1);
			from->out_link[from->out_degree] = ft_strcpy(from->out_link[from->out_degree], to->name);
		}
		else
		{
			tmp = from->out_link[from->out_degree];
			from->out_link[from->out_degree] = ft_strjoin(from->out_link[from->out_degree], to->name);
			free(tmp);
		}
		from->out_degree++;
		if (to->in_link[to->in_degree] == NULL)
		{
			to->in_link[to->in_degree] = ft_strnew(ft_strlen(from->name) + 1);
			to->in_link[to->in_degree] = ft_strcpy(to->in_link[to->in_degree], from->name);
		}
		else
		{
			tmp = to->in_link[to->in_degree];
			to->in_link[to->in_degree] = ft_strjoin(to->in_link[to->in_degree] , from->name);
			free(tmp);
		}
		to->in_degree++;
	}
	free_split_str(&split_connections);
}

void			add_el_to_hash_map(t_lem *lem, char **lines, char **split_str)
{
	t_room	*new_room;

	new_room = create_room(&split_str[0], ft_atoi(split_str[1]), ft_atoi(split_str[2]));
	ht_set(lem->ht, split_str[0], &new_room);
	lem->rooms_cap++;
	free_split_str(&split_str);
	free(*lines);
	*lines = NULL;
}

void			add_start_or_end(t_lem *lem, char **split_str, char **lines)
{
	char	*tmp_dest;
	t_room	*new_room;
	int		ret;

	tmp_dest = ft_strdup(*lines);
	free(*lines);
	(*lines) = NULL;
	free_split_str(&split_str);
	ret = get_next_line(lem->fd, lines);
//	ft_printf("%s\n", *lines);
	split_str = ft_strsplit(*lines, ' ');
	if (ret <= 0 || !is_room(lem, split_str, lines))
	{
//		printf("NO END OR START\n");
		exit(free_data(&lem));
	}
//	ft_printf("PASS???\n");
	if (ft_strequ(tmp_dest, "##end") && !(lem->start_end_flag & 1)) {
		lem->start_end_flag ^= 1;
		lem->end = ft_strdup(split_str[0]);
	}
	if (ft_strequ(tmp_dest, "##start") && !(lem->start_end_flag & 2))
	{
		lem->start_end_flag ^= 2;
		lem->start = ft_strdup(split_str[0]);
	}
	new_room = create_room(&split_str[0], ft_atoi(split_str[1]), ft_atoi(split_str[2]));
	ht_set(lem->ht, split_str[0], &new_room);
	lem->rooms_cap++;
	free_split_str(&split_str);
	free(*lines);
	*lines = NULL;
	free(tmp_dest);
}

int check_coord_valid(char *x, char *y)
{
	if (ft_str_is_numeric_no_spaces(x)
		&& ft_strlen(x) <= 10
		&& ft_str_is_numeric_no_spaces(y)
		&& ft_strlen(y) <= 10)
		return (1);
	return (0);
}

void	terminate(char *s)
{
	ft_putstr(s);
	exit(1);
}


void		get_info(t_lem *lem, char *file_name)
{
	char	*lines;
	char	**split_str;
	
	(void)file_name;

	while (get_next_line(lem->fd, &lines) > 0)
	{
		concat_lines(lem->concat_lines, lines, &lem->concat_bytes, &lem->concat_mult);
		if (lem->errors == 0)
		{
			split_str = ft_strsplit(lines, ' ');
			if (is_comment(lines))
			{
				free_line_info(&split_str, &lines);
				continue;
			}
			else if (is_ant(lines, split_str))
			{
				if (check_ants_num(lines))
					lem->ants = ft_atoi(split_str[0]);
				else
				{
					free_line_info(&split_str, &lines);
					free_data(&lem);
					terminate(RED"ERROR: Number of ants is incorrent\n"RESET);
					lem->errors++;
				}
			}
			else if (is_end_or_start(lem, split_str, &lines))
				add_start_or_end(lem, split_str, &lines);
			else if (is_room(lem, split_str, &lines))
				add_el_to_hash_map(lem, &lines, split_str);
			else if (ft_strchr(lines, '-'))
				add_link(lem, lines, split_str);
			else
				free_line_info(&split_str, &lines);
		}
	}
}
