/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:19:58 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 22:02:39 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char *lem_strdub(char *str, size_t delimeter)
{
	char *new_biggest_link;
	size_t i;

	i = 0;
	new_biggest_link = ft_strnew(delimeter);
	while (i < delimeter && str[i])
	{
		new_biggest_link[i] = str[i];
		i++;
	}
	new_biggest_link[i] = '\0';
	return (new_biggest_link);
}

int get_biggest_delimeter(t_lem *lem, char *str, size_t size)
{
	char *new_biggest_link;
	int biggest_delimeter;
	size_t i;

	i = 0;
	new_biggest_link = ft_strnew(size);
	biggest_delimeter = 0;
	while (i < size)
	{
		new_biggest_link[i] = str[i];
		if (ht_get(lem->ht, new_biggest_link))
		{
			biggest_delimeter = ++i;
			continue;
		}
		i++;
	}
	free(new_biggest_link);
	return (biggest_delimeter);
}

int is_link(t_lem *lem, char **split_str, char **lines)
{
	char *link_str;
	char *from_str;
	char *to_str;
	t_room	*from;
	t_room	*to;
	int biggest_delimeter;

	(void)lines;
	link_str = split_str[0];
	biggest_delimeter = get_biggest_delimeter(lem, link_str, ft_strlen(link_str));
	from_str = lem_strdub(link_str, biggest_delimeter);
	to_str = lem_strdub(link_str + biggest_delimeter + 1,  ft_strlen(link_str));
	if (!from_str || !to_str)
	{
		free(from_str);
		free(to_str);
		return (0);
	}
	from = ht_get(lem->ht, from_str);
	to = ht_get(lem->ht, to_str);
	if (!from || !to)
	{
		free(from_str);
		free(to_str);
		return (0);
	}
	free(from_str);
	free(to_str);
	return (1);
}

int is_end_or_start(t_lem *lem, char **split_str, char **lines)
{
	if (ht_get(lem->ht, split_str[0]))
	{
		free_line_info(&split_str, lines);
		terminate(&lem, DUPLICATE_ROOM);
	}
	if (ft_strequ(split_str[0], "##end") && lem->end == NULL)
		return (2);
	else if (ft_strequ(split_str[0], "##start") && lem->start == NULL)
		return (1);
	return (0);
}

int is_room(t_lem *lem, char **split_str, char **lines)
{
	if (ht_get(lem->ht, split_str[0]))
	{
		free_line_info(&split_str, lines);
		terminate(&lem, DUPLICATE_ROOM);
	}
	if (split_str[0] && split_str[1] && split_str[2])
	{
		if (check_coord_valid(split_str[1], split_str[2]))
			return (1);
	}
	return (0);
}

int is_connection(t_lem *lem, char **split_connections)
{
	if (ht_get(lem->ht, split_connections[0]) && ht_get(lem->ht, split_connections[1]))
		return (1);
	return (0);
}

int is_ant(t_lem * lem, char *lines, char **split_str)
{
	if (ft_str_is_numeric_no_spaces(split_str[0]) && split_str[1] == NULL)
	{
		if (!check_ants_num(lines))
		{
			free_line_info(&split_str, &lines);
			terminate(&lem, INCORRECT_ANTS);
		}
	}
	if (ft_str_is_numeric_no_spaces(split_str[0]) && split_str[1] == NULL && !ft_strchr(lines, '-'))
		return (1);
	return (0);
}

int is_comment(const char *lines)
{
	if (lines[0] == '#' && lines[1] != '#')
		return (1);
	return (0);
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

int check_ants_num(char *lines)
{
	int num_limit;
	long long		temp_val;

	num_limit = lines[0] == '-' ? NUM_LEN_WITH_SIGN : NUM_LEN_NO_SIGN;

	if (ft_str_is_numeric_no_spaces(lines) && ft_strlen(lines) <= (size_t)num_limit)
	{
		temp_val = ft_atol(lines);
		if (temp_val > MAX_INTEGER || temp_val < 0)
			return (0);
	} else
		return (0);
	return (1);
}