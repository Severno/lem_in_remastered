/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:08:09 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 22:20:39 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void free_seen(t_ht **seen)
{
	int i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		if ((*seen)->entries[i]->value)
			free((*seen)->entries[i]->key);
		free((*seen)->entries[i++]);
//		freed_entries++;
	}
	free((*seen)->entries);
	free((*seen));
}


void			free_str_links(char ***in_links, char ***out_links, char ***links)
{
	int		i;

	i = 0;
	while (i < MIN_LINKS)
	{
		free((*in_links)[i++]);
//		freed_in++;
	}
	free(*in_links);
	*in_links = 0;
	i = 0;
	while (i < MIN_LINKS)
	{
		free((*out_links)[i++]);
//		freed_out++;
	}
	i = 0;
	while (i < MIN_LINKS)
	{

		free((*links)[i++]);
//		freed_out++;
	}
	free(*links);
	*links = 0;
}

void			free_split_str(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		if ((*tab)[i] != NULL)
			free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = 0;
}

void free_line_info(char ***split_str, char **lines)
{
	free_split_str(split_str);
	free(*lines);
	*lines = NULL;
}

void terminate(t_lem **lem, char *str)
{
	(void)lem;
	ft_putstr(str);
	exit(free_data(lem));
}