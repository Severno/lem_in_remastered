/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_links_connections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:37:54 by sapril            #+#    #+#             */
/*   Updated: 2020/02/20 19:38:16 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int get_real_out_links(t_lem *lem, t_room *curr_room)
{
	int i;
	int real_out_links;

	i = 0;
	real_out_links = 0;
	if (!curr_room)
		return (0);
	while (i < MIN_LINKS)
	{
		if (curr_room->out_links[i] != NULL
		&& curr_room->out_links[i][0] != '\0'
		&& ht_get(lem->ht, curr_room->out_links[i]))
			real_out_links++;
		i++;
	}
	return (real_out_links);
}

int get_real_in_links(t_lem *lem, t_room *curr_room)
{
	int i;
	int real_in_links;

	i = 0;
	real_in_links = 0;
	if (!curr_room)
		return (0);
	while (i < MIN_LINKS)
	{
		if (curr_room->in_links[i] != NULL
		&& curr_room->in_links[i][0] != '\0'
		&& ht_get(lem->ht, curr_room->in_links[i]))
			real_in_links++;
		i++;
	}
	return (real_in_links);
}
